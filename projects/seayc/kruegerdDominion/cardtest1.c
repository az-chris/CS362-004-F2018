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
    //G.handCount[1] = 7;
    //added coded to make Daniel K's code work.
    int card, choice1, choice2, choice3;
    int * bonus;
    card = 1;
    choice1 = 1;
    choice2 = 2;
    choice3 = 3;
    bonus = 0;

    cardEffectSmithy(card, choice1, choice2, choice3, &G, 7, bonus);
    if(G.handCount[1] == 9)
    {
        printf("Passed: Picked up 3 cards\n");
    }
    else
    {
        printf("Failed: Expected 10 cards, had %d cards\n", G.handCount[1]);
    }
    if(G.deckCount[1] == 22)
    {
        printf("Passed: Deck reduced by 3 cards\n");
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
