#include "functions.h"
#include <stdlib.h>

// Create champion (randomly pick from structs default int assignment) 
CHAMPION createChampion ( ) {
    CHAMPION c = rand() % 3;
    return c;
}

// Computes random num between min and max
int getRandomNumber ( int min, int max ) {
    return rand() % (max - min + 1) + min;
}

// Assign points based on probabilities given
int getChampionPoints ( CHAMPION c ) {
    int championPoints = 0;

    if (c == MAGE) {
        championPoints = rand() % (8 - 1 + 1) + 1;
    }
    else if (c == FIGHTER) {
        championPoints = rand() % (7 - 3 + 1) + 3;
    }
    else if (c == TANK) {
        championPoints = rand() % (9 - 5 + 1) + 5;
    }

    return championPoints;
}

// Prints string of the passed enum champion type
void printChampion ( CHAMPION c ) {
    if (c == MAGE) {
        printf("MAGE");
    }
    else if (c == FIGHTER) {
        printf("FIGHTER");
    }
    else if (c == TANK) {
        printf("TANK");
    }
}

/*
    Takes all function values as input and creates pointer
    value for points at start of round (for point dynamics as champions progress)
    DOES NOT TAKE VALUE, VALS UPDATED DIRECTLY AS POINTERS LOL
    STEP 1: Define champions (use create champion)
    STEP 2: Assign points (use getChampionPoints)
    STEP 3: Perform fight (compare weight of championPoints, assign winner)
*/
void playRound ( int* p1_total, int* p2_total, CHAMPION c1, 
    int c1_points, CHAMPION c2, int c2_points) {
        p1_total; // don't reassign just sum... this is pointer
        p2_total; // don't reassign just sum... this is pointer
        c1 = createChampion();
        c1_points;
        c2 = createChampion();
        c2_points;
    }


    /* Champion rules table:

            MAGE                            FIGHTER                         TANK
    MAGE    Higher Points Wins              Higher Points Wins              Higher Points Wins            
            Wins = gains their points       Wins = gains their points       Wins = gains their points
            loses = loses points            loses = loses points            loses = loses points
            tie = nothing happens           tie = nothing happens           tie = nothing happens

    FIGHTER Higher Points Wins              Both Win and gain points        Higher Points Wins            
            Wins = gains their points                                       Wins = gains their points
            loses = no penalty                                              loses = loses points
            tie = nothing happens                                           tie = nothing happens

    TANK    Higher Points Wins              Higher Points Wins              Nothing Happens            
            Wins = gains their points       Wins = gains their points       
            loses = loses points            loses = loses points            
            tie = nothing happens           tie = nothing happens           
    */