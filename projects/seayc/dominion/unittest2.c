#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    UNIT TEST 2  *********************\n");
    printf("----------------------------------------------------\n");
    int i;
    struct gameState G;
    for(i = 0; i < treasure_map+1; i++)
    {
        G.supplyCount[i] = 10;
    }
    G.supplyCount[province] = 0;
    int testResult;
    testResult = isGameOver(&G);
    if(1 == testResult)
    {
        printf("Passed: No provinces remaining ended the game\n");
    }
    else
    {
        printf("Failed: No provinces remaining did not end game\n");
    }

    G.supplyCount[province] = 10;
    testResult = isGameOver(&G);
    if(0 == testResult)
    {
        printf("Passed: No game endeding conditions\n");
    }
    else
    {
        printf("Failed: Game falsly ended early\n");
    }

    G.supplyCount[ambassador] = 0;
    G.supplyCount[smithy] = 0;
    G.supplyCount[salvager] = 0;

    testResult = isGameOver(&G);
    if(1 == testResult)
    {
        printf("Passed: 3 cards supplies empty ended the game\n");
    }
    else
    {
        printf("Failed: 3 card supplies being empty did not end the game\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END UNIT TEST 2  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
