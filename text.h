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

extern Letter LETTER_A;
extern Letter LETTER_C;
extern Letter LETTER_D;
extern Letter LETTER_G;
extern Letter LETTER_M;
extern Letter LETTER_P;
extern Letter LETTER_R;
extern Letter LETTER_S;
extern Letter LETTER_U;
