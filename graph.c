#include "graph.h"
#include <stdio.h>



// Constants
const int GRAPH_WIDTH = 120;
const int GRAPH_HEIGHT = 120;
const int GRAPH_TITLE_SCALE = 8;
const int GRAPH_TITLE_PADDING = GRAPH_TITLE_SCALE * 10;
const int LINE_PADDING = 5;
const int NUM_VALUES = GRAPH_WIDTH - 2 * LINE_PADDING;

// initGraphs must be called after initText
void initGraphs(void) {
    CPU_GRAPH.title[0] = LETTER_C;
    CPU_GRAPH.title[1] = LETTER_P;
    CPU_GRAPH.title[2] = LETTER_U;
    CPU_GRAPH.pos.x = 150;
    CPU_GRAPH.pos.y = 100;
    CPU_GRAPH.getUsage = dummy;
    CPU_GRAPH = initLinkedList(CPU_GRAPH);

    GPU_GRAPH.title[0] = LETTER_G;
    GPU_GRAPH.title[1] = LETTER_P;
    GPU_GRAPH.title[2] = LETTER_U;
    GPU_GRAPH.pos.x = 750;
    GPU_GRAPH.pos.y = 100;
    GPU_GRAPH.getUsage = dummy;
    GPU_GRAPH = initLinkedList(GPU_GRAPH);

    RAM_GRAPH.title[0] = LETTER_R;
    RAM_GRAPH.title[1] = LETTER_A;
    RAM_GRAPH.title[2] = LETTER_M;
    RAM_GRAPH.pos.x = 150;
    RAM_GRAPH.pos.y = 350;
    RAM_GRAPH.getUsage = getMemoryUsage;
    RAM_GRAPH = initLinkedList(RAM_GRAPH);

    SSD_GRAPH.title[0] = LETTER_S;
    SSD_GRAPH.title[1] = LETTER_S;
    SSD_GRAPH.title[2] = LETTER_D;
    SSD_GRAPH.pos.x = 750;
    SSD_GRAPH.pos.y = 350;
    SSD_GRAPH.getUsage = dummy;
    SSD_GRAPH = initLinkedList(SSD_GRAPH);
}

Graph initLinkedList(Graph graph) {
    graph.startNode = malloc(sizeof(ListNode));
    ListNode* node = graph.startNode;

    for (int i = 0; i < NUM_VALUES-1; i++) {
        node->value = 0;
        ListNode* new = malloc(sizeof(ListNode));
        node->next = new;
        node = new;
    }

    node->value = 0;
    node->next = NULL;

    graph.endNode = node;

    return graph;
}

Graph addValueToGraph(Graph graph, float value) {
    ListNode* oldNode = graph.startNode;
    graph.startNode = graph.startNode->next;
    free(oldNode);

    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = NULL;
    graph.endNode->next = newNode;
    graph.endNode = newNode;

    return graph;
}

Graph updateGraph(Graph graph) {
    // Add usage data to graph
    float usage = graph.getUsage();
    graph = addValueToGraph(graph, usage);

    return graph;
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
