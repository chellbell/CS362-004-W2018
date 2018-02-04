/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * test the smithy card functionality
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;    
    int maxHandCount = 5;    
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // set up game
    initializeGame(numPlayer, k, seed, &G);

    // test #1
    // set up hand & game state for player 0
    G.hand[0][0] = smithy;
    int deckCount = G.deckCount[0];
    printf("%d\n", deckCount);
    int discardCount = G.discardCount[0];
    printf("%d\n", discardCount);

    printf ("TESTING smithy functionality:\n");

    // test whether deck count increased by 2 after playing smithy
    // (draw 3 but minus 1 for playing smithy)
    playCard(0, 0, 0, 0, &G);
    if (G.deckCount[0] - deckCount == 2) {
        printf("test #1 passed\n");
    } else {
        printf("test #1 failed\n");
    }

    // test #2
    // test whether discard pile increased by 1 with previous successful play
    G.supplyCount[province] = 0;
    if (G.discardCount[0] - discardCount == 1) {
        printf("test #2 passed\n");
    } else {
        printf("test #2 failed\n");
    }     

    return 0;
}