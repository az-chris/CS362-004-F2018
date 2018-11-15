#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    CARD TEST 1  *********************\n");
    printf("----------------------------------------------------\n");
    struct gameState G;
    G.deckCount[1] = 25;
    G.handCount[1] = 7;
    smithyCard(&G, 7, 1);
    if(G.handCount[1] == 10)
    {
        printf("Passed: Picked up 4 cards\n");
    }
    else
    {
        printf("Failed: Expected 10 cards, had %d cards\n", G.handCount[1]);
    }
    if(G.deckCount[1] == 21)
    {
        printf("Passed: Deck reduced by 4 cards\n");
    }
    else
    {
        printf("Failed: Expected 21 cards in deck, had %d cards\n", G.handCount[1]);
    }


    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 1  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
