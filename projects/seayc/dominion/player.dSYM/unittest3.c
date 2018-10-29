#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    UNIT TEST 3  *********************\n");
    printf("----------------------------------------------------\n");
    struct gameState G;
    G.supplyCount[province] = 0;
    int testResult;
    testResult = supplyCount(province, &G);
    if( 0 == testResult)
    {
        printf("Passed: Card supply was 0\n");
    }
    else
    {
        printf("Failed: Card supply not correctly returned\n");
    }
    G.supplyCount[province] = 10;
    testResult = supplyCount(province, &G);
    if( 10 == testResult)
    {
        printf("Passed: Card supply was 10\n");
    }
    else
    {
        printf("Failed: Card supply not correctly returned\n");
    }

    printf("----------------------------------------------------\n");
    printf("************    END UNIT TEST 3  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
