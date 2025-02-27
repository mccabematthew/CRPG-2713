#include "functions.h"

/*
 *  File Name: main.c
 *  Assignment: CRPG-2317 An autonomous RPG that only requires round amount as input
 *  Dev: Matthew McCabe, mee749
 *  
 *  Description:                                                                WIP WIP WIP WIP
 *  STEP 1: Create variables (pay attention to scope)
 *      - for round amt
 *      - to pass to playRound
 *          - Define CHAMPION champions (use create champion)
 *          - Define int points c1_points, int c2_points(init to 0 as we are using pointers to update)
 *          - Define pointers int* p1_total, int* p2_total  
 *  STEP 2: Take input for round amt and use for main game loop header
 *  STEP 3: Perform fight using PlayRound()
 * 
*/

/*
 *  Function: main
 *  -------------------
 *  Description: 
 *      Utilizes functions prototyped in functions.h, and defined in functions.c
 *      in order to create a game loop. The game is an automated RPG that takes
 *      user input for amount of rounds and then plays rounds where "Champions" 
 *      engage in "combat" and the winner's points are added to their total at 
 *      the end of each round. Round and player informationn is output until the
 *      game reaches the user determined final round at which point the winner
 *      is declared and "GAME OVER!!" is shown.
 *  Returns: 0
*/
int main( ) 
{
    int roundAmount = 0;
    CHAMPION playerChampion1;
    CHAMPION playerChampion2;
    int champion1Points;
    int champion2Points;
    int* champion1PointTotal = champion1Points; // Pointers for dynamic updating within game loop
    int* champion2PointTotal = champion2Points;




    printf( "Enter the number of rounds: " ); 
    scanf( "%d", &roundAmount );

    // // Main game loop
    // /*
    //     What values do I want to update globally
    // */
    for( int i = 1; i < roundAmount + 1; i++ )
    {
        playerChampion1 = createChampion( ); // Creates new champions for players every round
        playerChampion2 = createChampion( );
        champion1Points =  getChampionPoints( playerChampion1 ); // Reassigns respective strength points every round
        champion2Points = getChampionPoints( playerChampion2 );



        printf( "ROUND %d:\n--------\n", i );
        printf( "Player points at  the start of the round -- P1 = %d\tP2 = %d\n", 
            champion1PointTotal, champion2PointTotal ); // Should pointers go here?
        printf( "P1: %s-%d vs  P2: %s-%d", playerChampion1, champion1Points, playerChampion2, champion2Points ); // use print champion toget output given in test cases for Champion
        // // playRound updates vals
        // playRound( champion1PointTotal, champion2PointTotal, playerChampion1, 
        //     champion1Points, playerChampion2, champion2Points ); // Does battle logic and something else WIP

        printf( "Player points at the end of the round -- P1 = %d\tP2 = %d\n", champion1PointTotal, champion2PointTotal );
    }


    return 0;
}

// Sample Output

// ###############  RUN-1  ############### 

// Enter the number of rounds: 5

// ROUND 1
// --------
// Player points at the start of the round  --  P1 = 0		P2 = 0
// P1 : MAGE-5	 vs 	P2 : FIGHTER-4
// Player 1 (MAGE) wins and gains their current points.
// Player 2 (FIGHTER) loses but with no penalty.
// Player points at the end of the round  --  P1 = 5		P2 = 0


// ROUND 2
// --------
// Player points at the start of the round  --  P1 = 5		P2 = 0
// P1 : FIGHTER-7	 vs 	P2 : FIGHTER-7
// Both players gain their current points.
// Player points at the end of the round  --  P1 = 12		P2 = 7


// ROUND 3
// --------
// Player points at the start of the round  --  P1 = 12		P2 = 7
// P1 : MAGE-2	 vs 	P2 : TANK-6
// Player 1 (MAGE) wins and gains their current points.
// Player 2 (TANK) loses their current points.
// Player points at the end of the round  --  P1 = 14		P2 = 1


// ROUND 4
// --------
// Player points at the start of the round  --  P1 = 14		P2 = 1
// P1 : FIGHTER-4	 vs 	P2 : FIGHTER-3
// Both players gain their current points.
// Player points at the end of the round  --  P1 = 18		P2 = 4


// ROUND 5
// --------
// Player points at the start of the round  --  P1 = 18		P2 = 4
// P1 : FIGHTER-3	 vs 	P2 : MAGE-7
// Player 1 (FIGHTER) loses but with no penalty.
// Player 2 (MAGE) wins and gains their current points.
// Player points at the end of the round  --  P1 = 18		P2 = 11


// GAME OVER!!
// P1 Won
