#include "src/include/SDL2/SDL.h"

/*
Structure for a letter
points is a list of points that will be connected by straight lines in pairs
numPairs is the number of pairs

Each letter is 5 (width) by 9 (height)
*/

typedef struct {
    int numPairs;
    SDL_Point* points;
} Letter;

int initText(void);

void drawLetter(SDL_Renderer* renderer, Letter letter, int offsetX, int offsetY, int scale);


// ------ LETTERS ------

Letter LETTER_A;
Letter LETTER_C;
Letter LETTER_D;
Letter LETTER_G;
Letter LETTER_M;
Letter LETTER_P;
Letter LETTER_R;
Letter LETTER_S;
Letter LETTER_U;
