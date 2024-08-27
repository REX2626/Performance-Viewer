#include "graph.h"

// Constants
const int GRAPH_WIDTH = 120;
const int GRAPH_HEIGHT = 120;
const int GRAPH_TITLE_SCALE = 8;
const int GRAPH_TITLE_PADDING = GRAPH_TITLE_SCALE * 10;

// initGraphs must be called after initText
void initGraphs(void) {
    CPU_GRAPH.title[0] = LETTER_C;
    CPU_GRAPH.title[1] = LETTER_P;
    CPU_GRAPH.title[2] = LETTER_U;
    CPU_GRAPH.pos.x = 150;
    CPU_GRAPH.pos.y = 100;
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
}
