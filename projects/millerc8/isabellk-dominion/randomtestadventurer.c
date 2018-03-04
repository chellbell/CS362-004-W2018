/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * randomly test the adventurer card functionality
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"


int main() {
    srand((unsigned)time(NULL));
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
               
    // run the random tests 100 times
    for (int r = 0; r < 100; r++) {
        struct gameState G;
        // set up game & game state
        initializeGame(numPlayer, k, seed, &G);
        G.whoseTurn = 0;

        // create random game state of counts were before we played any cards
        // hand & discard counts are any random number less than the max hand / deck size
        // create a successful random numactions (i.e. nonzero)
        G.handCount[0] = (rand() % MAX_HAND);
        G.discardCount[0] = (rand() % MAX_DECK);
        int prevHandCount = G.handCount[0];
        int prevDiscardCount = G.discardCount[0];

        // randomly throw treasures into the hand
        for (int t = 0; t < G.handCount[0]; t++) {
            if (rand() % 1 == 0) {
                G.hand[0][t] = copper;
            }
        }

        int prevTreasures = 0;
        for (int i = 0; i < G.handCount[0]; i++) {
            if (G.hand[0][i] == copper || 
                G.hand[0][i] == silver ||
                G.hand[0][i] == gold) {
                prevTreasures++;
            }
        }

        // test #1
        // put adventurer in slot 1
        G.hand[0][0] = adventurer;

        printf ("TESTING adventurer functionality:\n");

        // test whether hand count increased by 2 after playing smithy
        // (+2 treasure card drawn & -1 card discarded)
        playCard(0, -1, -1, -1, &G);
        if (G.handCount[0] - prevHandCount == 1) {
            printf("test #1 passed\n");
        } else {
            printf("test #1 failed\n");
        }

        // test #2
        // test whether discard pile increased with previous successful play
        // cannot rely on a constant increase amount b/c of variation in drawing treasures
        if (G.discardCount[0] > prevDiscardCount) {
            printf("test #2 passed\n");
        } else {
            printf("test #2 failed\n");
        }     

        // test #3
        // test whether treasures increases by 1 or 2 with previous successful play
        // (may not have 2 treasures left to add)
        int postTreasures = 0;
        for (int i = 0; i < G.handCount[0]; i++) {
            if (G.hand[0][i] == copper || 
                G.hand[0][i] == silver ||
                G.hand[0][i] == gold) {
                postTreasures++;
            }
        }

        if ((postTreasures - prevTreasures) == 1 ||
            (postTreasures - prevTreasures) == 2) {
            printf("test #3 passed\n");
        } else {
            printf("test #3 failed\n");
        }     

        // test #4
        // test whether treasure is found in the discard pile after previous play
        // (treasure shouldn't be discarded as part of adventurer)
        for (int i = 0; i < G.discardCount[0]; i++) {
            if (G.discard[0][i] == copper ||
                G.discard[0][i] == silver ||
                G.discard[0][i] == gold) {
                printf("test #4 failed\n");
            }
        }
        printf("test #4 passed\n");
    }

    return 0;
}