/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * test the buyCard() function
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
    // set up game
    initializeGame(numPlayer, k, seed, &G);

    // test #1
    // set up numbuys
    G.numBuys = 0;

    printf ("TESTING buyCard():\n");

    // test whether buy allowed when numbuys is 0
    // should be prevented, bc returns -1
    if (buyCard(3, &G) == 0) {
        printf("test #1 failed\n");
    } else {
        printf("test #1 passed\n");
    }

    // test #2
    // test whether buy allowed when supply of requested card = 0
    // fix numBuys
    G.numBuys = 30;
    // set supply count
    G.supplyCount[province] = 0;
    if (buyCard(province, &G) == 0) {
        printf("test #2 failed\n");
    } else {
        printf("test #2 passed\n");
    }

    // test #3
    // test whether buy allowed when not enough coins to buy
    // fix supply count
    G.supplyCount[province] = 30;
    // no coins
    G.coins = 0;
    if (buyCard(province, &G) == 0) {
        printf("test #3 failed\n");
    } else {
        printf("test #3 passed\n");
    }

    // test #4
    // test whether buy allowed when all conditions met
    G.coins = 100;
    if (buyCard(province, &G) == 0) {
        printf("test #4 passed\n");
    } else {
        printf("test #4 failed\n");
    }

    // now switch into testing side effects after successful buy
    // test #5
    // setup here is used for tests 5-7
    G.coins = 100;
    G.numBuys = 10;
    G.phase = 0;
    buyCard(province, &G);
    // test whether coins were reduced by province cost
    if (G.coins == 92) {
        printf("test #5 passed\n");
    } else {
        printf("test #5 failed\n");
    }

    // test #6
    // test whether numBuys was reduced by the previous purchase
    if (G.numBuys == 9) {
        printf("test #6 passed\n");
    } else {
        printf("test #6 failed\n");
    }    

    // test #7
    // test whether state phase was incremented by the previous purchase
    if (G.phase == 1) {
        printf("test #7 passed\n");
    } else {
        printf("test #7 failed\n");
    }     

    return 0;
}