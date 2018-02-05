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
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // set up game & game state
    initializeGame(numPlayer, k, seed, &G);
    G.whoseTurn = 0;
    // note what counts were before we played any cards
    int prevHandCount = G.handCount[0];
    int prevDiscardCount = G.discardCount[0];

    // test #1
    // put smithy in slot 1
    G.hand[0][0] = smithy;

    printf ("TESTING smithy functionality:\n");

    // test whether hand count increased by 2 after playing smithy
    // (+3 drawn & -1 discarded)    
    playCard(0, -1, -1, -1, &G);
    if (G.handCount[0] - prevHandCount == 3) {
        printf("test #1 passed\n");
    } else {
        printf("test #1 failed\n");
    }

    // test #2
    // test whether discard pile increased by 1 with previous successful play
    if (G.discardCount[0] - prevDiscardCount == 1) {
        printf("test #2 passed\n");
    } else {
        printf("test #2 failed\n");
    }     

    return 0;
}