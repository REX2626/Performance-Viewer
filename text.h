#include "src/include/SDL2/SDL.h"

/*
Structure for a letter
points is a list of points that will be connected by straight lines in pairs
numPairs is the number of pairs

Each letter is 4 (width) by 8 (height)
*/
typedef struct {
    int numPairs;
    SDL_Point* points;
} Letter;

void initText(void);

void drawLetter(SDL_Renderer* renderer, Letter letter, int offsetX, int offsetY, int scale);


// ------ LETTERS ------
Letter LETTER_C;
