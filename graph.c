#include "graph.h"
#include <stdio.h>



// Constants
const int GRAPH_WIDTH = 120;
const int GRAPH_HEIGHT = 120;
const int GRAPH_TITLE_SCALE = 8;
const int GRAPH_TITLE_PADDING = GRAPH_TITLE_SCALE * 10;
const int LINE_PADDING = 5;
const int NUM_VALUES = GRAPH_WIDTH - 2 * LINE_PADDING;

int initGraph(Graph* graph, Letter letter1, Letter letter2, Letter letter3, int x, int y, float (*getUsage)(void)) {
    graph->title[0] = letter1;
    graph->title[1] = letter2;
    graph->title[2] = letter3;
    graph->pos.x = x;
    graph->pos.y = y;
    graph->getUsage = getUsage;
    if (initLinkedList(graph) == -1) return -1;
    graph->usages = malloc(0);
    graph->numUsages = 0;
}

// initGraphs must be called after initText
int initGraphs(void) {
    if (initGraph(
        &CPU_GRAPH,
        LETTER_C,
        LETTER_P,
        LETTER_U,
        150,
        100,
        getProcessorUsage
    ) == -1) return -1;

    if (initGraph(
        &GPU_GRAPH,
        LETTER_G,
        LETTER_P,
        LETTER_U,
        750,
        100,
        dummy
    ) == -1) return -1;

    if (initGraph(
        &RAM_GRAPH,
        LETTER_R,
        LETTER_A,
        LETTER_M,
        150,
        350,
        getMemoryUsage
    ) == -1) return -1;

    if (initGraph(
        &SSD_GRAPH,
        LETTER_S,
        LETTER_S,
        LETTER_D,
        750,
        350,
        dummy
    ) == -1) return -1;

    return 0;
}

int initLinkedList(Graph* graph) {
    graph->startNode = malloc(sizeof(ListNode));
    if (graph->startNode == NULL) return -1;
    ListNode* node = graph->startNode;

    for (int i = 0; i < NUM_VALUES-1; i++) {
        node->value = 0;
        ListNode* new = malloc(sizeof(ListNode));
        if (new == NULL) return -1;
        node->next = new;
        node = new;
    }

    node->value = 0;
    node->next = NULL;

    graph->endNode = node;

    return 0;
}

int addValueToGraph(Graph* graph, float value) {
    ListNode* oldNode = graph->startNode;
    graph->startNode = graph->startNode->next;
    free(oldNode);

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) return -1;
    newNode->value = value;
    newNode->next = NULL;
    graph->endNode->next = newNode;
    graph->endNode = newNode;

    return 0;
}

int updateGraphUsages(Graph* graph) {
    // Add usage to arry of usages for current frame
    graph->numUsages++;
    graph->usages = realloc(graph->usages, graph->numUsages * sizeof(float));

    if (graph->usages == NULL) return -1;
    float usage = graph->getUsage();
    if (usage == -1) return -1;
    graph->usages[graph->numUsages-1] = usage;

    return 0;
}

int updateGraph(Graph* graph) {
    // Add average of frame usages to graph values
    float total = 0;
    for (int i = 0; i < graph->numUsages; i++) {
        total += graph->usages[i];
    }

    float average = total / graph->numUsages;
    if (addValueToGraph(graph, average) == -1) return -1;

    // Reset usages to 0
    graph->numUsages = 0;

    return 0;
}

void drawGraph(SDL_Renderer* renderer, Graph graph) {
    // Draw title
    int center = graph.pos.x + GRAPH_WIDTH/2;
    drawLetter(renderer, graph.title[0], center - GRAPH_TITLE_SCALE*7, graph.pos.y, GRAPH_TITLE_SCALE);
    drawLetter(renderer, graph.title[1], center - GRAPH_TITLE_SCALE*2, graph.pos.y, GRAPH_TITLE_SCALE);
    drawLetter(renderer, graph.title[2], center + GRAPH_TITLE_SCALE*3, graph.pos.y, GRAPH_TITLE_SCALE);

    // Draw vertical left line
    SDL_RenderDrawLine(
        renderer,
        graph.pos.x,
        graph.pos.y + GRAPH_TITLE_PADDING,
        graph.pos.x,
        graph.pos.y + GRAPH_TITLE_PADDING + GRAPH_HEIGHT);

    // Draw horizontal bottom line
    SDL_RenderDrawLine(
        renderer,
        graph.pos.x,
        graph.pos.y + GRAPH_TITLE_PADDING + GRAPH_HEIGHT,
        graph.pos.x + GRAPH_WIDTH,
        graph.pos.y + GRAPH_TITLE_PADDING + GRAPH_HEIGHT);

    // Draw usage lines
    int x = 0;
    ListNode* node = graph.startNode;
    while (node->next) {
        SDL_RenderDrawLine(renderer,
            graph.pos.x + LINE_PADDING + x,
            graph.pos.y + GRAPH_TITLE_PADDING + GRAPH_HEIGHT * (1 - node->value),
            graph.pos.x + LINE_PADDING + ++x,
            graph.pos.y + GRAPH_TITLE_PADDING + GRAPH_HEIGHT * (1 - node->next->value)
        );
        node = node->next;
    }
}
