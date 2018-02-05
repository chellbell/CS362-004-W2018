/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * test the great hall card functionality
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
    int maxHandCount = 5;  
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // set up game & game state
    initializeGame(numPlayer, k, seed, &G);
    G.whoseTurn = 0;
    // note what counts were before we played any cards
    int prevHandCount = G.handCount[0];
    int prevDeckCount = G.deckCount[0];
    int prevDiscardCount = G.discardCount[0];
    int prevNumActions = G.numActions;

    // printf("%d\n", G.handCount[0]);
    // printf("%d\n", G.discardCount[0]);
    // printf("%d\n", prevNumActions);

    // test #1
    // put greathall in slot 1
    G.hand[0][0] = great_hall;

    printf ("TESTING greathall functionality:\n");

    // test whether deck count increased by 0 after playing smithy
    // (+1 card drawn & -1 card discarded)
    playCard(0, -1, -1, -1, &G);
    if (G.handCount[0] - prevHandCount == 0) {
        printf("test #1 passed\n");
    } else {
        printf("test #1 failed\n");
    }
    // printf("%d\n", G.handCount[0]);

    // test #2
    // test whether discard pile increased by 1 with previous successful play
    if (G.discardCount[0] - prevDiscardCount == 1) {
        printf("test #2 passed\n");
    } else {
        printf("test #2 failed\n");
    }     
    // printf("%d\n", G.discardCount[0]);

    // test #3
    // test whether numActions increases by 0 with previous successful play
    // (1 actions added & -1 action from playing that card)
    if (G.numActions - prevNumActions == 0) {
        printf("test #3 passed\n");
    } else {
        printf("test #3 failed\n");
    }     

    // printf("%d\n", G.numActions);

    return 0;
}