/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * test the gainCard() function
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
    int numPlayer = 3;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // set up game
    initializeGame(numPlayer, k, seed, &G);

    // test #1
    // set up supply count
    G.supplyCount[province] = 0;

    printf ("TESTING gainCard():\n");

    // test whether province gain allowed when province supply is 0
    // should be prevented, gc returns -1
    if (gainCard(province, &G, 0, 0) == 0) {
        printf("test #1 failed\n");
    } else {
        printf("test #1 passed\n");
    }

    // test #2
    // test whether successful gain decreases supply count
    // fix province supply count
    G.supplyCount[province] = 30;
    gainCard(province, &G, 0, 0);
    if (G.supplyCount[province] == 29) {
        printf("test #2 passed\n");
    } else {
        printf("test #2 failed\n");
    }

    // test #3
    // test whether discard count incremented when discarding
    // fix supply count
    G.discardCount[0] = 0;
    gainCard(province, &G, 0, 0);
    if (G.discardCount[0] == 1) {
        printf("test #3 passed\n");
    } else {
        printf("test #3 failed\n");
    }

    // test #4
    // test whether card placed in proper position of discard
    if (G.discard[0][G.discardCount[0]] == province) {
        printf("test #4 passed\n");
    } else {
        printf("test #4 failed\n");
    }

    return 0;
}