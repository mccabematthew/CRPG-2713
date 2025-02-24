#include "functions.h"
#include <random>

// TODO: Write Logic
CHAMPION createChampion ( );

// Computes random num between min and max
int getRandomNumber ( int min, int max ) {
    return rand() % (max - min + 1) + min;
}

// TODO: Write Logic
int getChampionPoints ( CHAMPION c );

// TODO: Write Logic
void printChampion ( CHAMPION c );

// TODO: Write Logic
void playRound ( int* p1_total, int* p2_total, CHAMPION c1, 
    int c1_points, CHAMPION c2, int c2_points);