#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

// Player character types
typedef enum {
    MAGE,
    FIGHTER,
    TANK
} CHAMPION;


// Function prototypes
CHAMPION createChampion ( );

int getRandomNumber ( int min, int max );

int getChampionPoints ( CHAMPION c );

void printChampion ( CHAMPION c );

void playRound ( int* p1_total, int* p2_total, CHAMPION c1, 
    int c1_points, CHAMPION c2, int c2_points);


#endif