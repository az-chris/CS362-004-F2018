#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    UNIT TEST 4  *********************\n");
    printf("----------------------------------------------------\n");
    struct gameState G;
    G.whoseTurn = 0;
    int testResult;
    testResult = whoseTurn(&G);
    if( 0 == testResult)
    {
        printf("Passed: Whose turn player was 0\n");
    }
    else
    {
        printf("Failed: Whose turn player not correctly returned\n");
    }
    G.whoseTurn = 2;
    testResult = whoseTurn(&G);
    if( 2 == testResult)
    {
        printf("Passed: Whose turn player was 2\n");
    }
    else
    {
        printf("Failed: Whose turn player not correctly returned\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END UNIT TEST 4  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
