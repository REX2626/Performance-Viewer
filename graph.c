#include "graph.h"

void drawGraph(SDL_Renderer* renderer, SDL_Rect rect) {
    // Draw vertical left line
    SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x, rect.y + rect.h);

    // Draw horizontal bottom line
    SDL_RenderDrawLine(renderer, rect.x, rect.y + rect.h, rect.x + rect.w, rect.y + rect.h);
}
