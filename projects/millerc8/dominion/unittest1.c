/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * test the isGameOver() function
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
    int i;
    int seed = 1000;
    struct gameState G;

    // test #1
    // set up the supply counts
    for (i = 0; i < 25; i++) {
        G.supplyCount[i] = 10;
    }
    // now set provinces to 0
    G.supplyCount[province] = 0;

    printf ("TESTING isGameOver():\n");

    // test whether gameover recognized when province supply = 0
    // & all other supplies have cards
    // game should be over, igo returns 1
    if (isGameOver(&G) == 0) {
        printf("test #1 failed\n");
    } else {
        printf("test #1 passed\n");
    }

    // test #2
    // test whether gameover recognized when province supply = 1
    // & all other supplies have cards
    // game should not be over, igo returns 0
    G.supplyCount[province]++;
    if (isGameOver(&G) == 0) {
        printf("test #2 passed\n");
    } else {
        printf("test #2 failed\n");
    }

    // test #3
    // now clear supply counts EXCEPT provinces
    for (i = 0; i < 25; i++) {
        if (i != province) {
            G.supplyCount[i] = 0;
        }
    }
    // test whether gameover recognized when no supplies exist except provinces
    // game should be over, igo returns 1
    if (isGameOver(&G) == 0) {
        printf("test #3 failed\n");
    } else {
        printf("test #3 passed\n");
    }

    return 0;
}