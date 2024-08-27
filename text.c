#include "text.h"

void drawLetter(SDL_Renderer* renderer, Letter letter, int offsetX, int offsetY, int scale) {
    for (int i = 0; i < letter.numPairs; i++) {
        SDL_Point point1 = letter.points[i*2];
        SDL_Point point2 = letter.points[i*2+1];
        SDL_RenderDrawLine(
            renderer,
            point1.x * scale + offsetX,
            point1.y * scale + offsetY,
            point2.x * scale + offsetX,
            point2.y * scale + offsetY);
    }
}

// ------ LETTERS ------

int initText(void) {
    // Returns 0 for success, -1 for failure
    SDL_Point* points;

    LETTER_A.numPairs = 4;
    points = malloc(8 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 0;
    points[0].y = 7;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 3;
    points[3].y = 0;
    points[4].x = 3;
    points[4].y = 0;
    points[5].x = 3;
    points[5].y = 7;
    points[6].x = 0;
    points[6].y = 3;
    points[7].x = 3;
    points[7].y = 3;
    LETTER_A.points = points;

    LETTER_C.numPairs = 3;
    points = malloc(6 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 3;
    points[0].y = 0;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 0;
    points[3].y = 7;
    points[4].x = 0;
    points[4].y = 7;
    points[5].x = 3;
    points[5].y = 7;
    LETTER_C.points = points;

    LETTER_D.numPairs = 5;
    points = malloc(10 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 0;
    points[0].y = 7;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 1;
    points[3].y = 0;
    points[4].x = 1;
    points[4].y = 0;
    points[5].x = 3;
    points[5].y = 3;
    points[6].x = 3;
    points[6].y = 3;
    points[7].x = 1;
    points[7].y = 7;
    points[8].x = 1;
    points[8].y = 7;
    points[9].x = 0;
    points[9].y = 7;
    LETTER_D.points = points;

    LETTER_G.numPairs = 5;
    points = malloc(10 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 3;
    points[0].y = 0;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 0;
    points[3].y = 7;
    points[4].x = 0;
    points[4].y = 7;
    points[5].x = 3;
    points[5].y = 7;
    points[6].x = 3;
    points[6].y = 7;
    points[7].x = 3;
    points[7].y = 3;
    points[8].x = 3;
    points[8].y = 3;
    points[9].x = 1;
    points[9].y = 3;
    LETTER_G.points = points;

    LETTER_M.numPairs = 4;
    points = malloc(8 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 0;
    points[0].y = 7;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 1;
    points[3].y = 7;
    points[4].x = 1;
    points[4].y = 7;
    points[5].x = 3;
    points[5].y = 0;
    points[6].x = 3;
    points[6].y = 0;
    points[7].x = 3;
    points[7].y = 7;
    LETTER_M.points = points;

    LETTER_P.numPairs = 4;
    points = malloc(8 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 0;
    points[0].y = 0;
    points[1].x = 0;
    points[1].y = 7;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 3;
    points[3].y = 0;
    points[4].x = 3;
    points[4].y = 0;
    points[5].x = 3;
    points[5].y = 3;
    points[6].x = 3;
    points[6].y = 3;
    points[7].x = 0;
    points[7].y = 3;
    LETTER_P.points = points;

    LETTER_R.numPairs = 5;
    points = malloc(10 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 0;
    points[0].y = 7;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 3;
    points[3].y = 0;
    points[4].x = 3;
    points[4].y = 0;
    points[5].x = 3;
    points[5].y = 3;
    points[6].x = 3;
    points[6].y = 3;
    points[7].x = 0;
    points[7].y = 3;
    points[8].x = 0;
    points[8].y = 3;
    points[9].x = 3;
    points[9].y = 7;
    LETTER_R.points = points;

    LETTER_S.numPairs = 5;
    points = malloc(10 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 3;
    points[0].y = 0;
    points[1].x = 0;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 0;
    points[3].x = 0;
    points[3].y = 3;
    points[4].x = 0;
    points[4].y = 3;
    points[5].x = 3;
    points[5].y = 3;
    points[6].x = 3;
    points[6].y = 3;
    points[7].x = 3;
    points[7].y = 7;
    points[8].x = 3;
    points[8].y = 7;
    points[9].x = 0;
    points[9].y = 7;
    LETTER_S.points = points;

    LETTER_U.numPairs = 3;
    points = malloc(6 * sizeof(SDL_Point));
    if (points == NULL) return -1;
    points[0].x = 0;
    points[0].y = 0;
    points[1].x = 0;
    points[1].y = 7;
    points[2].x = 0;
    points[2].y = 7;
    points[3].x = 3;
    points[3].y = 7;
    points[4].x = 3;
    points[4].y = 7;
    points[5].x = 3;
    points[5].y = 0;
    LETTER_U.points = points;

    return 0;
}
