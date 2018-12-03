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

    printf("v2.5\n");

    int card, choice1, choice2, choice3;
    int * bonus;
    card = copper;
    choice1 = copper;
    choice2 = copper;
    choice3 = copper;
    bonus = 0;

    struct gameState G;
    G.deck[1][0] = copper;
    G.deck[1][1] = copper;
    G.deck[1][2] = copper;
    int firstGold;
    int secondGold;
    G.handCount[1] = 1;
    G.handCount[0] = 1;
    G.handCount[2] = 1;
    G.deckCount[1] = 3;
    cardEffectAdventurer(card, choice1, choice2, choice3, &G, 0 ,bonus);
    if(G.hand[1][0] == copper)
    {
        printf("Success: First copper added to player hand\n");
        firstGold = 0;
    }
    else if(G.hand[2][0] == copper)
    {
        printf("Failed: First copper added to Player +1 player's hand\n");
        firstGold = 1;
    }
    else if(G.hand[0][0] == copper)
    {
        printf("Failed: First copper added to Player -1 player's hand\n");
        firstGold = 1;
    }
    else
    {
        printf("Failed: First copper not added to player hand\n");
        firstGold = 1;
    }
    if(G.hand[1][1] == copper)
    {
        printf("Success: Second copper added to player hand\n");
        secondGold = 0;
    }
    else
    {
        printf("Failed: Second copper not added to player hand\n");
        secondGold = 1;
    }
    //Modified to check for bug
    if(G.hand[1][2] == copper)
    {
         printf("Failed: Third copper added to player hand\n");
        secondGold = 0;
    }
    else
    {
        printf("Passed: Third copper not added to player hand\n");
        secondGold = 1;
    }
    if( secondGold == 1 || firstGold == 1 )
    {
        printf("Failed: Both coppers not added to player hand\n");
    }
    else
    {
        printf("Success: Both coppers added to player hand\n");
    }


    printf("----------------------------------------------------\n");
    printf("************    END CARD TEST 2  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
