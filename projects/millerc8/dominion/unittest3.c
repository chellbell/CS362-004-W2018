/* -----------------------------------------------------------------------
 * Using testUpdateCoins.c as a template
 * test the supplyCount() function
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

    printf ("TESTING supplyCount():\n");

    // test correct supply count for provinces
    if (supplyCount(province, &G) == 0) {
        printf("test #1 passed\n");
    } else {
        printf("test #1 failed\n");
    }

    // test #2
    // test correct supply count for copper
    if (supplyCount(copper, &G) == 10) {
        printf("test #2 passed\n");
    } else {
        printf("test #2 failed\n");
    }

    // test #3
    // test correct supply count for smithy
    if (supplyCount(smithy, &G) == 10) {
        printf("test #3 passed\n");
    } else {
        printf("test #3 failed\n");
    }

    return 0;
}