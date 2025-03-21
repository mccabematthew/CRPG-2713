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
    int i = 0;
    int roundAmount = 0;
    CHAMPION playerChampion1;
    CHAMPION playerChampion2;
    int championOnePoints;
    int championTwoPoints;
    int championOnePointTotal = 0;
    int championTwoPointTotal = 0;

    // Seed random number generator
    srand(time(NULL));

    printf( "Enter the number of rounds: " ); 
    scanf( "%d", &roundAmount );
    printf( "\n" ); 
    
    // Game loop
    for( i = 1; i < roundAmount + 1; i++ )
    {
        playerChampion1 = createChampion( ); // Creates new champions for players every round
        playerChampion2 = createChampion( );
        championOnePoints = getChampionPoints( playerChampion1 ); // Reassigns respective strength points every round
        championTwoPoints = getChampionPoints( playerChampion2 );

        printf( "ROUND %d\n--------\n", i );
        printf( "Player points at the start of the round  --  P1 = %d\t\tP2 = %d\n", 
            championOnePointTotal, championTwoPointTotal ); // Show initial rounds points
        
        // Display champion information
        printf( "P1 : " );
        printChampion(playerChampion1);
        printf("-%d\t vs \tP2 : ", championOnePoints);
        printChampion(playerChampion2);
        printf("-%d\n", championTwoPoints);
        
        // Play the round and update points
        playRound(&championOnePointTotal, &championTwoPointTotal, playerChampion1, 
            championOnePoints, playerChampion2, championTwoPoints);

        printf( "Player points at the end of the round  --  P1 = %d\t\tP2 = %d\n", 
            championOnePointTotal, championTwoPointTotal ); // Updated total points
        printf( "\n" ); 
    }

    printf("GAME OVER!!\n");
    if(championOnePointTotal > championTwoPointTotal) {
        printf("P1 Won\n");
    } else if(championTwoPointTotal > championOnePointTotal) {
        printf("P2 Won\n");
    } else {
        printf("It's a tie!\n");
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
