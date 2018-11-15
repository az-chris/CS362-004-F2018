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
    struct gameState G;
    int loops = 1;
    int i;
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
        adventurerCard(&G, 0 ,1);
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

        if( copperCount == 0)
        {
            printf("Success: No Coppers were picked up\n");
        }
        else
        {
            printf("Failure: Coppers were added to the hand\n");
        }

        if( (silverCount + goldCount) >= 2)
        {
            printf("Success: Two Silvers or Gold were added\n");
        }
        else if( (silverCount + goldCount) == 1)
        {
            printf("Failure: Only one Silver or Gold was added\n");
        }
        else
        {
            printf("Failure: No Silver or Gold was added\n");
        }



    }


    printf("----------------------------------------------------\n");
    printf("************    RANDOM CARD TEST 1  ****************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}
