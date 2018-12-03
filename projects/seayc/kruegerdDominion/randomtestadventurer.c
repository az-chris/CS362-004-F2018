#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define RandomNumberInInterval(min,max) rand()%(max-min+1)+min


int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    RANDOM TEST 1  *******************\n");
    printf("----------------------------------------------------\n");
    srand(time(NULL));   // Initialization, should only be called once.
    int i;
    struct gameState G;
    struct gameState H;
    int loops = 500;
    int card, choice1, choice2, choice3;
    int * bonus;

    for(i = 0; i < loops; i++)
    {
        int i;
        i = 0;
        int coins;
        int tempCount;
        tempCount = 0;
        coins = 0;
        while( coins < 25)
        {
            int temp;
            temp = RandomNumberInInterval(4,6);
            if(temp == 4)
            {
                G.deck[1][i] = copper;
                tempCount += 1;
                //printf("Added a copper at %d\n", i);
                i++;
            }
            else if(temp == 5)
            {
                G.deck[1][i] = silver;
                coins += 1;
                tempCount += 1;
                //printf("Added a silver at %d\n", i);
                i++;

            }
            else if(temp == 6)
            {
                G.deck[1][i] = gold;
                coins += 1;
                tempCount += 1;
                //printf("Added a gold at %d\n", i);
                i++;

            }
        }
        G.handCount[1] = 1;
        G.deckCount[1] = tempCount;
        cardEffectAdventurer(card, choice1, choice2, choice3, &G, 1 ,bonus);
        int copperCount;
        copperCount = 0;
        int silverCount;
        silverCount = 0;
        int goldCount;
        goldCount = 0;
        int j;
        for(j = 0; j < tempCount+1; j++)
        {
            if(G.hand[1][j] == copper)
            {
                copperCount += 1;
                printf("Found a silver at %d\n", j);
                
            }
            else if(G.hand[1][j] == silver)
            {
                silverCount += 1;
                printf("Found a silver at %d\n", j);
            }
            else if(G.hand[1][j] == gold)
            {
                goldCount += 1;
                printf("Found a gold at %d\n", j);
            }
        }



        if( (silverCount + goldCount + copperCount) >= 2)
        {
            printf("Success: Two Coppers, Silvers, or Gold were added\n");
        }
        else if( (silverCount + goldCount) == 1)
        {
            printf("Failure: Only one Copper, Silver, or Gold was added\n");
        }
        else
        {
            printf("Failure: No Copper,Silver, or Gold was added\n");
        }



    }


    printf("----------------------------------------------------\n");
    printf("************    RANDOM CARD TEST 1  ****************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
