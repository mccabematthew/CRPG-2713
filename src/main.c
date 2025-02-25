#include "functions.h"

int main() {
    /*
    
    */
    int roundAmount = 0;


    printf("Enter the number of rounds: ");
    scanf("%d", &roundAmount);

    // playRound();


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
