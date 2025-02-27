#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

// Player champion types
typedef enum 
{
    MAGE,
    FIGHTER,
    TANK
} CHAMPION;


/*
 *  Function: createChampion
 *  -------------------
 *  Description: Create champion (randomly pick from structs default int assignment) 
 *  Returns: One of the three champion types
*/
CHAMPION createChampion ( );

/*
 *  Function: getRandomNumber
 *  -------------------
 *  Description: Computes random num between min and max
 *      min: Minimum value
 *      max: Maximum value
 *  Returns: Random number
*/
int getRandomNumber ( int min, int max );

/*
 *  Function: getChampionPoints
 *  -------------------
 *  Description: Assign points based on probabilities given
 *      c: Champion value
 *  Returns: championPoints - A random number within the given probabilities
*/
int getChampionPoints ( CHAMPION c );

/*
 *  Function: printChampion
 *  -------------------
 *  Description: Prints a string version of the passed enum champion type
 *      c: Champion value
 *  Returns: Nothing
*/
void printChampion ( CHAMPION c );

/*
 *  Function: playRound
 *  -------------------
 *  Description: Params are func vals that are declared globally in main                        WIP WIP WIP WIP
 *      STEP 1: Perform fight (compare weight of championPoints, assign winner)
 *      STEP 2: Reassign new points based on logic
 *  Parameters:
 *      p1_total: Player one's total points (to be added to by c1_points)
 *      p2_total: Player two's total points (to be added to by c2_points)
 *      c1: Player one's champion value
 *      c1_points: Player one's current round points (to be updated at end)
 *      c2: Player two's champion value
 *      c2_points: Player two's current round points (to be updated at end)
 *  Returns: Nothing
*/
void playRound ( int* p1_total, int* p2_total, CHAMPION c1, 
    int c1_points, CHAMPION c2, int c2_points);


#endif