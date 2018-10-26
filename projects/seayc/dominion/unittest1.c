#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"


#define VERBOSE_MODE

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    UNIT TEST 1  *********************\n");
    printf("----------------------------------------------------\n");
    //Variables set up
    int numCardsInDeck = 27;
    int i;
    int result;
    // values the switch should return
    // NOTE: not cross reference to physical card values
    int cardValues[] = {0, 2, 5, 8, 0, 3, 6, 6,
                     5, 4, 4, 5, 4, 4, 3, 4,
                     3, 5, 3, 5, 3, 4, 2, 5,
                     4, 4, 4};

    char cardNames[27][15] =    {
                                    "curse",
                                    "estate",
                                    "duchy",
                                    "province",
                                    "copper",
                                    "silver",
                                    "gold",
                                    "adventurer",
                                    "council_room",
                                    "feast",
                                    "gardens",
                                    "mine",
                                    "remodel",
                                    "smithy",
                                    "village",
                                    "baron",
                                    "great_hall",
                                    "minion",
                                    "steward",
                                    "tribute",
                                    "ambassador",
                                    "cutpurse",
                                    "embargo",
                                    "outpost",
                                    "salvager",
                                    "sea_hag",
                                    "treasure_map"
                                };

    for(i = 0; i < numCardsInDeck -1; i++)
    {
        int test = NULL;
        test = getCost(i);
        #ifdef VERBOSE_MODE
            printf("Card Name: %s\n", cardNames[i]);
            printf("Expected Card Value = %d, Test Value = %d\n", cardValues[i], test);
        #endif
        if( test != cardValues[i])
        {
            result = -1;
            break;
        }

    }

    printf("----------------------------------------------------\n");
    printf("************    END UNIT TEST 1  *******************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return result;
}
