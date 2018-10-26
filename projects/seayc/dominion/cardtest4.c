#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    CARD TEST 4  *********************\n");
    printf("----------------------------------------------------\n");

    struct gameState G;

    G.supplyCount[curse] = 500;

    int testResult;

    testResult = supplyCount( curse, &G);

    if( testResult == 500 )
    {
        printf("Success: Correct supply returned\n");
    }
    else
    {
        printf("Failed: Incorrect supply returned\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 4  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
