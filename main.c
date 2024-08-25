#include <stdio.h>
#include <stdbool.h>
#include "src/include/SDL2/SDL.h"



const unsigned short WIDTH = 1000;
const unsigned short HEIGHT = 600;


int main(int argc, char* argv[]) {
    // Initial message & SDL version
    SDL_version version;
    SDL_GetVersion(&version);
    printf("Initializing PerfView (SDL version: %d.%d.%d)\n", (int) version.major, (int) version.minor, (int) version.patch);

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
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
