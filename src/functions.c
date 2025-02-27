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
 * 
*/

// Create champion (randomly pick from structs default int assignment) 
CHAMPION createChampion( ) 
{
    CHAMPION c = rand( ) % 3;
    return c;
}

// Computes random num between min and max
int getRandomNumber( int min, int max ) 
{
    return rand( ) % ( max - min + 1 ) + min;
}

// Assign points based on probabilities given
int getChampionPoints( CHAMPION c ) 
{
    int championPoints = 0;

    if( c == MAGE ) 
    {
        championPoints = rand( ) % ( 8 - 1 + 1 ) + 1;
    }
    else if( c == FIGHTER ) 
    {
        championPoints = rand( ) % ( 7 - 3 + 1 ) + 3;
    }
    else if( c == TANK ) 
    {
        championPoints = rand( ) % ( 9 - 5 + 1 ) + 5;
    }

    return championPoints;
}

// Prints string of the passed enum champion type
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
    Params are func vals that are declared globally in main
    STEP 1: Perform fight (compare weight of championPoints, assign winner)
    STEP 2: Reassign new points based on logic

*/
void playRound( int* p1_total, int* p2_total, CHAMPION c1, 
    int c1_points, CHAMPION c2, int c2_points ) 
{
    /*some pseudo logic to think*/
        
}

    // Sample Output

    // ROUND 1
    // --------
    // Player points at the start of the round  --  P1 = 0		P2 = 0
    // P1 : MAGE-5	 vs 	P2 : FIGHTER-4
    // Player 1 (MAGE) wins and gains their current points.
    // Player 2 (FIGHTER) loses but with no penalty.
    // Player points at the end of the round  --  P1 = 5		P2 = 0
