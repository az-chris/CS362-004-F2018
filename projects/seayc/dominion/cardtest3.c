#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    CARD TEST 3  *********************\n");
    printf("----------------------------------------------------\n");

    struct gameState G;

    G.whoseTurn = 5;

    int testResult;

    testResult = whoseTurn(&G);

    if(testResult == 5)
    {
        printf("Success: Correct whose turn returned\n");
    }
    else
    {
        printf("Failed: Incorrect whose turn returned\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 3  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
