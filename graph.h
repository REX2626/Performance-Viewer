#include "src/include/SDL2/SDL.h"
#include "stats.h"
#include "text.h"



typedef struct ListNode{
    float value;
    struct ListNode* next;
} ListNode;

typedef struct {
    Letter title[3];
    SDL_Point pos;
    float (*getUsage)(void);
    ListNode* startNode;
    ListNode* endNode;
    float* usages;
    int numUsages;
} Graph;

int initGraphs(void);

int initLinkedList(Graph* graph);

int updateGraphUsages(Graph* graph);

int updateGraph(Graph* graph);

void drawGraph(SDL_Renderer* renderer, Graph graph);

// ------ GRAPHS ------

extern const int NUM_VALUES;

extern Graph CPU_GRAPH;
extern Graph GPU_GRAPH;
extern Graph RAM_GRAPH;
extern Graph SSD_GRAPH;
