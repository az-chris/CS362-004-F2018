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
    G.numActions = 2;
    G.deckCount[1] = 25;
    G.handCount[1] = 25;

    villageCard( &G , 24 , 1);
    if( G.numActions == 3 )
    {
        printf("Success: number of actions correctly incremented\n");
    }
    else
    {
        printf("Failed: number of actions incorrectly incremented\n");
    }
    if( G.handCount[1] == 25)
    {
        printf("Success: 1 card drawn and 1 card discarded\n");
    }
    else
    {
        printf("Failed: incorrect number of cards drawn and/or discarded\n");
    }
    if( G.deckCount[1] == 24)
    {
        printf("Success: deck reduced by 1\n");
    }
    else
    {
        printf("Failed: deck not correctly reduced\n");
    }



    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 4  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
