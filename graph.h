#include "src/include/SDL2/SDL.h"
#include "text.h"

typedef struct {
    Letter title[3];
    SDL_Point pos;
} Graph;

void initGraphs(void);

void drawGraph(SDL_Renderer* renderer, Graph graph);

// ------ GRAPHS ------

Graph CPU_GRAPH;
