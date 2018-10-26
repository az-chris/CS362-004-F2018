#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    CARD TEST 2  *********************\n");
    printf("----------------------------------------------------\n");

    struct gameState G;
    G.deck[1][0] = gold;
    G.deck[1][1] = gold;
    G.deck[1][2] = gold;
    int firstGold;
    int secondGold;
    G.handCount[1] = 1;
    G.deckCount[1] = 2;
    adventurerCard(&G, 0 ,1);
    if(G.hand[1][1] == gold)
    {
        printf("Success: First gold added to player hand\n");
        firstGold = 0;
    }
    else
    {
        printf("Failed: First gold not added to player hand\n");
        firstGold = 1;
    }
    if(G.hand[1][2] == gold)
    {
        printf("Success: Second gold added to player hand\n");
        secondGold = 0;
    }
    else
    {
        printf("Failed: Second gold not added to player hand\n");
        secondGold = 1;
    }
    if( secondGold == 1 || firstGold == 1 )
    {
        printf("Failed: Both golds not added to player hand\n");
    }
    else
    {
        printf("Success: Both golds added to player hand\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 2  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
