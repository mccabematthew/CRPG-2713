#include "functions.h"
#include <stdlib.h>

/*
 *  File Name: functions.c
 *  Assignment: CRPG-2317 An autonomous RPG that only requires round amount as input
 *  Dev: Matthew McCabe, mee749
 * 
 *  
 *  Description:
 *  Defines all functions from protoypes in functions.h
*/

/*
 *  Function: createChampion
 *  -------------------
 *  Description: Create champion (randomly pick from structs default int assignment) 
 *  Returns: One of the three champion types
*/
CHAMPION createChampion( ) 
{
    CHAMPION c = rand( ) % 3;
    return c;
}

/*
 *  Function: getRandomNumber
 *  -------------------
 *  Description: Computes random num between min and max
 *      min: Minimum value
 *      max: Maximum value
 *  Returns: Random number
*/
int getRandomNumber( int min, int max ) 
{
    return rand( ) % ( max - min + 1 ) + min;
}

/*
 *  Function: getChampionPoints
 *  -------------------
 *  Description: Assign points based on probabilities given
 *      c: Champion value
 *  Returns: championPoints - A random number within the given probabilities
*/
int getChampionPoints( CHAMPION c ) 
{
    int championPoints = 0;

    if( c == MAGE ) 
    {
        championPoints = getRandomNumber( 1, 8 );
    }
    else if( c == FIGHTER ) 
    {
        championPoints = getRandomNumber( 3, 7 );
    }
    else if( c == TANK ) 
    {
        championPoints = getRandomNumber( 5, 9 );
    }

    return championPoints;
}

/*
 *  Function: printChampion
 *  -------------------
 *  Description: Prints a string version of the passed enum champion type
 *      c: Champion value
 *  Returns: Nothing
*/
void printChampion( CHAMPION c ) 
{
    if( c == MAGE ) 
    {
        printf( "MAGE" );
    }
    else if( c == FIGHTER ) 
    {
        printf( "FIGHTER" );
    }
    else if( c == TANK ) 
    {
        printf( "TANK" );
    }
}

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
void playRound( int* p1_total, int* p2_total, CHAMPION c1, 
    int c1_points, CHAMPION c2, int c2_points ) 
{
        // Mage vs Mage Logic
    if( c1 == MAGE && c2 == MAGE ) 
    {
        if(c1_points > c2_points) // c1 wins and gains points, c2 loses their points
        {
            *p1_total = *p1_total + c1_points;
            *p2_total = *p2_total - c2_points;
            if(*p2_total < 0) *p2_total = 0; // Ensure points don't go negative
            printf("Player 1 (MAGE) wins and gains their current points.\n");
            printf("Player 2 (MAGE) loses their current points.\n");
        }
        else if(c1_points < c2_points) // c2 wins and gains points, c1 loses their points
        {
            *p2_total = *p2_total + c2_points;
            *p1_total = *p1_total - c1_points;
            if(*p1_total < 0) *p1_total = 0; // Ensure points don't go negative
            printf("Player 1 (MAGE) loses their current points.\n");
            printf("Player 2 (MAGE) wins and gains their current points.\n");
        }
        else // Tie
        {
            *p1_total = *p1_total + c1_points;
            *p2_total = *p2_total + c2_points;
            printf("Both players gain their current points.\n");
        }
    }
    
    // Fighter vs Fighter Logic
    else if( c1 == FIGHTER && c2 == FIGHTER ) 
    {
        *p1_total = *p1_total + c1_points;
        *p2_total = *p2_total + c2_points;
        printf("Both players gain their current points.\n");
    }
    
    // Tank vs Tank Logic  
    else if( c1 == TANK && c2 == TANK )
    {
        if(c1_points > c2_points)
        {
            *p1_total = *p1_total + c1_points;
            printf("Player 1 (TANK) wins and gains their current points.\n");
            printf("Player 2 (TANK) loses but with no penalty.\n");
        }
        else if(c1_points < c2_points)
        {
            *p2_total = *p2_total + c2_points;
            printf("Player 1 (TANK) loses but with no penalty.\n");
            printf("Player 2 (TANK) wins and gains their current points.\n");
        }
        else // Tie
        {
            printf("Neither player gains points.\n");
        }
    }
    
    // Mage vs Fighter Logic
    else if( c1 == MAGE && c2 == FIGHTER )
    {
        *p1_total = *p1_total + c1_points;
        printf("Player 1 (MAGE) wins and gains their current points.\n");
        printf("Player 2 (FIGHTER) loses but with no penalty.\n");
    }
    else if( c1 == FIGHTER && c2 == MAGE )
    {
        *p2_total = *p2_total + c2_points;
        printf("Player 1 (FIGHTER) loses but with no penalty.\n");
        printf("Player 2 (MAGE) wins and gains their current points.\n");
    }
    
    // Mage vs Tank Logic
    else if( c1 == MAGE && c2 == TANK )
    {
        *p1_total = *p1_total + c1_points;
        *p2_total = *p2_total - c2_points;
        if(*p2_total < 0) *p2_total = 0; // Ensure points don't go negative
        printf("Player 1 (MAGE) wins and gains their current points.\n");
        printf("Player 2 (TANK) loses their current points.\n");
    }
    else if( c1 == TANK && c2 == MAGE )
    {
        *p2_total = *p2_total + c2_points;
        *p1_total = *p1_total - c1_points;
        if(*p1_total < 0) *p1_total = 0; // Ensure points don't go negative
        printf("Player 1 (TANK) loses their current points.\n");
        printf("Player 2 (MAGE) wins and gains their current points.\n");
    }
    
    // Fighter vs Tank Logic
    else if( c1 == FIGHTER && c2 == TANK )
    {
        *p1_total = *p1_total + c1_points;
        *p2_total = *p2_total - c2_points;
        if(*p2_total < 0) *p2_total = 0; // Ensure points don't go negative
        printf("Player 1 (FIGHTER) wins and gains their current points.\n");
        printf("Player 2 (TANK) loses their current points.\n");
    }
    else if( c1 == TANK && c2 == FIGHTER )
    {
        *p2_total = *p2_total + c2_points;
        *p1_total = *p1_total - c1_points;
        if(*p1_total < 0) *p1_total = 0; // Ensure points don't go negative
        printf("Player 1 (TANK) loses their current points.\n");
        printf("Player 2 (FIGHTER) wins and gains their current points.\n");
    }
        
}

    // Sample Output

    // ROUND 1
    // --------
    // Player points at the start of the round  --  P1 = 0		P2 = 0
    // P1 : MAGE-5	 vs 	P2 : FIGHTER-4
    // Player 1 (MAGE) wins and gains their current points.
    // Player 2 (FIGHTER) loses but with no penalty.
    // Player points at the end of the round  --  P1 = 5		P2 = 0
