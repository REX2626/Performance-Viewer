#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "src/include/SDL2/SDL.h"
#include "graph.h"



const int WIDTH = 1000;
const int HEIGHT = 600;
const double TOTAL_DURATION = 10;
const SDL_Colour BACKGROUND_COLOUR = {20, 20, 20, SDL_ALPHA_OPAQUE};
const SDL_Colour MAIN_COLOUR = {0, 255, 0, SDL_ALPHA_OPAQUE};

Graph CPU_GRAPH;
Graph GPU_GRAPH;
Graph RAM_GRAPH;
Graph SSD_GRAPH;

Letter LETTER_A;
Letter LETTER_C;
Letter LETTER_D;
Letter LETTER_G;
Letter LETTER_M;
Letter LETTER_P;
Letter LETTER_R;
Letter LETTER_S;
Letter LETTER_U;


int update(void) {
    if (updateGraph(&CPU_GRAPH) == -1) return -1;
    if (updateGraph(&GPU_GRAPH) == -1) return -1;
    if (updateGraph(&RAM_GRAPH) == -1) return -1;
    if (updateGraph(&SSD_GRAPH) == -1) return -1;

    return 0;
}

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

    SDL_Window *window = SDL_CreateWindow("PerfView", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_ALWAYS_ON_TOP);
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
    if (initGraphs() == -1) {
        printf("Could not initialize graphs (likely insufficent memory)\n");
        return EXIT_FAILURE;
    }

    // Set up stats
    if (initStats() == -1) {
        printf("Could not initialize stats\n");
        return EXIT_FAILURE;
    }

    // Set up Main loop
    bool running = true;
    const double TICK_DURATION = TOTAL_DURATION / NUM_VALUES;

    SDL_Event event;

    // Main loop
    while (running) {

        clock_t time1 = clock();

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

        // Update
        if (update() == -1) {
            printf("Could not update (likely insufficient memory)\n");
            return EXIT_FAILURE;
        }

        // Graphics
        draw(renderer);

        // Sleep until tick is finished
        // TODO: Do 1 clock() call per loop, check difference with previous call
        // TODO: so that sleep calculations are taken into account
        // TODO: Instead of sleeping, carry on updating usage info but not graphics
        // TODO: Store multiple values for each point, and take average
        clock_t time2 = clock();
        double deltaTime = (double) (time2 - time1) / CLOCKS_PER_SEC;
        double sleepTime = max(0, 40 - deltaTime * 1000);

        Sleep(sleepTime);

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
