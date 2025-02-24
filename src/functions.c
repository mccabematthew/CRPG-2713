#include "functions.h"
#include <stdlib.h>

// TODO: Write Logic
CHAMPION createChampion ( ) {
    int championPoints = 0;
    int championNum = rand() % 3;
    CHAMPION playerChampion = championNum;

    if (playerChampion == 0) {
        playerChampion = MAGE;
        championPoints = rand() % (8 - 1 + 1) + 1;
    }
    else if (playerChampion == 1) {
        playerChampion = FIGHTER;
        championPoints = rand() % (7 - 3 + 1) + 3;
    }
    else if (playerChampion == 2) {
        playerChampion = TANK;
        championPoints = rand() % (9 - 5 + 1) + 5;
    }

    // if (playerChampion == 0) {
    //     championPoints = rand() % (8 - 1 + 1) + 1;
    // }
    // else if (playerChampion == 1) {
    //     championPoints = rand() % (7 - 3 + 1) + 3;
    // }
    // else if (playerChampion == 2) {
    //     championPoints = rand() % (9 - 5 + 1) + 5;
    // }

    return playerChampion;
}

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