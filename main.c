#include <stdio.h>
#include <stdbool.h>
#include "src/include/SDL2/SDL.h"
#include "graph.h"



const int WIDTH = 1000;
const int HEIGHT = 600;
const SDL_Colour BACKGROUND_COLOUR = {20, 20, 20, SDL_ALPHA_OPAQUE};
const SDL_Colour MAIN_COLOUR = {0, 255, 0, SDL_ALPHA_OPAQUE};


void draw(SDL_Renderer* renderer) {
    // Draw background
    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOUR.r, BACKGROUND_COLOUR.g, BACKGROUND_COLOUR.b, BACKGROUND_COLOUR.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, MAIN_COLOUR.r, MAIN_COLOUR.g, MAIN_COLOUR.b, MAIN_COLOUR.a);

    // Draw graphs
    drawGraph(renderer, CPU_GRAPH);
    drawGraph(renderer, GPU_GRAPH);
    drawGraph(renderer, RAM_GRAPH);
    drawGraph(renderer, SSD_GRAPH);

    // Update screen
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    // Initial message & SDL version
    SDL_version version;
    SDL_GetVersion(&version);
    printf("Initializing PerfView (SDL version: %d.%d.%d)\n", version.major, version.minor, version.patch);

    // Set up SDL
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_EVENTS) < 0) {
        printf("SDL could not initialize: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("PerfView", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        printf("Could not create renderer: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Set up text
    if (initText() == -1) {
        printf("Could not initialize text (likely insufficent memory)\n");
        return EXIT_FAILURE;
    }

    // Set up graphs
    initGraphs();

    // Set up Main loop
    bool running = true;

    SDL_Event event;

    // Main loop
    while (running){

        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {

                }
            }
        }

        // Graphics
        draw(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
