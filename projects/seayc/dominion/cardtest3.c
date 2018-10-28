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

    G.outpostPlayed = 5;

     outPostCard(&G , 2 , 1 );

    if(G.outpostPlayed == 6)
    {
        printf("Success: Correct outpost played turn returned\n");
    }
    else
    {
        printf("Failed: Incorrect outpost played returned\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 3  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
