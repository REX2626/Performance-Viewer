#include "src/include/SDL2/SDL.h"
#include "stats.h"
#include "text.h"

typedef struct {
    Letter title[3];
    SDL_Point pos;
} Graph;

void initGraphs(void);

void drawGraph(SDL_Renderer* renderer, Graph graph);

// ------ GRAPHS ------

extern Graph CPU_GRAPH;
extern Graph GPU_GRAPH;
extern Graph RAM_GRAPH;
extern Graph SSD_GRAPH;
