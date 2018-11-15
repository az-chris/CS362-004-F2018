#include <stdio.h>
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define RandomNumberInInterval(min,max) rand()%(max-min+1)+min

static const struct gameState EmptyGameState;

void genRandDeck(struct gameState *G);
void checkDeck(struct gameState *old, struct gameState *new, int player);
void supplyIntToEnum(int supplyEnum);

int main()
{
    printf("\n\n");
    printf("****************************************************\n");
    printf("**************    RANDOM TEST 2  *******************\n");
    printf("----------------------------------------------------\n");
    srand(time(NULL));   // Initialization, should only be called once.
    struct gameState G;
    struct gameState H;
    int loops = 500;
    int i;
    for(i = 0; i < loops; i++)
    {
        genRandDeck(&G);
        H = G;

        outPostCard(&G, 1, 1);
        checkDeck(&H, &G, 1);
        if(G.outpostPlayed == H.outpostPlayed+1)
        {
            printf("Success: Correct outpost played turn returned\n");
        }
        else
        {
            printf("Failed: Incorrect outpost played returned\n");
        }

        G = EmptyGameState;
        H = EmptyGameState;

    }


    printf("----------------------------------------------------\n");
    printf("************    RANDOM CARD TEST 2  ****************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}

void genRandDeck(struct gameState *G)
{
    int RandomPlayers;
    RandomPlayers = RandomNumberInInterval(2, 4);
    G->numPlayers = RandomPlayers;
    // Curse
    G->supplyCount[0] = RandomNumberInInterval(10, 50);
    // estate
    G->supplyCount[1] = RandomNumberInInterval(10, 50);
    // duchy
    G->supplyCount[2] = RandomNumberInInterval(10, 50);
    // province
    G->supplyCount[3] = RandomNumberInInterval(10, 50);
    // copper
    G->supplyCount[4] = RandomNumberInInterval(10, 50);
    // silver
    G->supplyCount[5] = RandomNumberInInterval(10, 50);
    // gold
    G->supplyCount[6] = RandomNumberInInterval(10, 50);
    // adventurer
    G->supplyCount[7] = RandomNumberInInterval(10, 50);
    // council room
    G->supplyCount[8] = RandomNumberInInterval(10, 50);
    // feast
    G->supplyCount[9] = RandomNumberInInterval(10, 50);
    // gardens
    G->supplyCount[10] = RandomNumberInInterval(10, 50);
    // mine
    G->supplyCount[11] = RandomNumberInInterval(10, 50);
    // remodel
    G->supplyCount[12] = RandomNumberInInterval(10, 50);
    // smithy
    G->supplyCount[13] = RandomNumberInInterval(10, 50);
    // village
    G->supplyCount[14] = RandomNumberInInterval(10, 50);
    // baron
    G->supplyCount[15] = RandomNumberInInterval(10, 50);
    // great hall
    G->supplyCount[16] = RandomNumberInInterval(10, 50);
    // minion
    G->supplyCount[17] = RandomNumberInInterval(10, 50);
    // steward
    G->supplyCount[18] = RandomNumberInInterval(10, 50);
    // tribute
    G->supplyCount[19] = RandomNumberInInterval(10, 50);
    // ambassador
    G->supplyCount[20] = RandomNumberInInterval(10, 50);
    // cutpurse
    G->supplyCount[21] = RandomNumberInInterval(10, 50);
    // embargo
    G->supplyCount[22] = RandomNumberInInterval(10, 50);
    // outpost
    G->supplyCount[23] = RandomNumberInInterval(10, 50);
    // salvager
    G->supplyCount[24] = RandomNumberInInterval(10, 50);
    // sea_hag
    G->supplyCount[25] = RandomNumberInInterval(10, 50);
    // treasure_map
    G->supplyCount[26] = RandomNumberInInterval(10, 50);

    int i;
    for(i = 0; i < treasure_map+1; i++)
    {
        G->embargoTokens[i] = RandomNumberInInterval(0, 5);
    }

    G->outpostPlayed = RandomNumberInInterval(0, 2);

    G->outpostTurn = RandomNumberInInterval(0, RandomPlayers);

    G->whoseTurn = RandomNumberInInterval(0, RandomPlayers);

    G->numActions = RandomNumberInInterval(1, 10);

    G->coins = RandomNumberInInterval(0, 100);

    G->numBuys = RandomNumberInInterval(1, 10);

    int j;
    int k;
    for(j = 0; j < treasure_map+1; j++)
    {
        for(k = 0; k < RandomPlayers; k++)
        {
            int temp_card;
            temp_card = RandomNumberInInterval(0, 20);
            if(G->supplyCount[j] >= temp_card)
            {
                G->hand[k][j] = temp_card;
                G->supplyCount[j] -= temp_card;
            }
            else
            {
                G->hand[k][j] = 0;
            }
        }
    }

    int p;
    for(p = 0; p < RandomPlayers; p++)
    {
        int pk;
        for(pk = 0; pk < treasure_map+1; pk++)
        {
            G->handCount[p] += G->hand[p][pk];
        }
    }

    int jj;
    int kk;
    for(jj = 0; jj < treasure_map+1; jj++)
    {
        for(kk = 0; kk < RandomPlayers; kk++)
        {
            int temp_card;
            temp_card = RandomNumberInInterval(0, 20);
            if(G->supplyCount[jj] >= temp_card)
            {
                G->deck[kk][jj] = temp_card;
                G->supplyCount[jj] -= temp_card;
            }
            else
            {
                G->deck[kk][jj] = 0;
            }
        }
    }

    int ii;
    for(ii = 0; ii < RandomPlayers; ii++)
    {
        int iz;
        for(iz = 0; iz < treasure_map+1; iz++)
        {
            G->handCount[ii] += G->hand[ii][iz];
        }
    }

    int a;
    int b;
    for(a = 0; a < treasure_map+1; a++)
    {
        for(b = 0; b < RandomPlayers; b++)
        {
            int temp_card;
            temp_card = RandomNumberInInterval(0, 20);
            if(G->supplyCount[a] >= temp_card)
            {
                G->deck[b][a] = temp_card;
                G->supplyCount[a] -= temp_card;
            }
            else
            {
                G->deck[b][a] = 0;
            }
        }
    }

    int c;
    for(c = 0; c < RandomPlayers; c++)
    {
        G->deckCount[c] = RandomNumberInInterval(0, 200);
    }



    int d;
    int e;
    e = RandomNumberInInterval(0, MAX_DECK);
    for(d = 0; d < e; d++)
    {
        G->playedCards[d] = RandomNumberInInterval(0, 26);
    }

    G->playedCardCount = RandomNumberInInterval(0, e);

}

void checkDeck(struct gameState *old, struct gameState *new, int player)
{
    if(old->numPlayers != new->numPlayers)
    {
        printf("Error: Expected %d players", old->numPlayers);
        printf(", had %d players \n", new->numPlayers);
    }

    int a;
    // check supply count
    for(a = 0; a < treasure_map+1; a++)
    {
        if(old->supplyCount[a] != new->supplyCount[a])
        {
            printf("Error: Expected %d ", old->supplyCount[a]);
            supplyIntToEnum(a);
            printf(" cards, had %d cards\n", new->supplyCount[a]);
        }
    }

    int b;
    for(b = 0; b < treasure_map+1; b++)
    {
        if(old->embargoTokens[b] != new->embargoTokens[b])
        {
            printf("Error: Expected %d embargo tokens on ", old->supplyCount[a]);
            supplyIntToEnum(a);
            printf(" cards, had %d embargo tokens \n", new->supplyCount[a]);
        }
    }


    if(old->outpostTurn != new->outpostTurn)
    {
        printf("Error: Expected %d outposts turn", old->supplyCount[a]);
        printf(", had %d outposts turn \n", new->supplyCount[a]);
    }

    if(old->whoseTurn != new->whoseTurn)
    {
        printf("Error: Expected %d turn", old->supplyCount[a]);
        printf(", had %d turn \n", new->supplyCount[a]);
    }

    if(old->numActions != new->numActions)
    {
        printf("Error: Expected %d numActions", old->supplyCount[a]);
        printf(", had %d numActions \n", new->supplyCount[a]);
    }

    if(old->numActions != new->numActions)
    {
        printf("Error: Expected %d numActions", old->supplyCount[a]);
        printf(", had %d numActions \n", new->supplyCount[a]);
    }

    if(old->coins != new->coins)
    {
        printf("Error: Expected %d coins", old->supplyCount[a]);
        printf(", had %d coins \n", new->supplyCount[a]);
    }

    if(old->numBuys != new->numBuys)
    {
        printf("Error: Expected %d numBuys", old->supplyCount[a]);
        printf(", had %d numBuys \n", new->supplyCount[a]);
    }

    int c;
    int d;
    for(c = 0; c < old->numPlayers; c++)
    {
        if(c == player)
        {
            c++;
        }
        else
        {
            for(d = 0; d < treasure_map+1; d++)
            {
                if(old->hand[c][d] != new->hand[c][d])
                {
                    printf("Error: Expected %d ", old->hand[c][d]);
                    supplyIntToEnum(d);
                    printf(" cards, had %d cards \n", new->hand[c][d]);
                }
            }
        }
    }

    int e;
    for(e = 0; e < old->numPlayers; e++)
    {
        if(e == player)
        {
            e++;
        }
        else
        {
            if(old->handCount[e] != new->handCount[e])
            {
                printf("Error: Expected %d ", old->handCount[e]);
                printf(" handcount, had %d handcount \n", new->handCount[e]);
            }
        }
    }

    int f;
    int g;
    for(f = 0; f < old->numPlayers; f++)
    {
        if(f == player)
        {
            f++;
        }
        else
        {
            for(g = 0; g < treasure_map+1; g++)
            {
                if(old->deck[f][g] != new->deck[f][g])
                {
                    printf("Error: Expected %d ", old->deck[f][g]);
                    supplyIntToEnum(g);
                    printf(" cards, had %d cards \n", new->deck[f][g]);
                }
            }
        }
    }

    int h;
    for(h = 0; h < old->numPlayers; h++)
    {
        if(h == player)
        {
            h++;
        }
        else
        {
            if(old->deckCount[h] != new->deckCount[h])
            {
                printf("Error: Expected %d ", old->deckCount[h]);
                printf(" handcount, had %d handcount \n", new->deckCount[h]);
            }
        }
    }

    int i;
    int j;
    for(i = 0; i < old->numPlayers; i++)
    {
        if(i == player)
        {
            i++;
        }
        else
        {
            for(j = 0; j < treasure_map+1; j++)
            {
                if(old->discard[i][j] != new->discard[i][j])
                {
                    printf("Error: Expected %d ", old->discard[i][j]);
                    supplyIntToEnum(j);
                    printf(" cards, had %d cards \n", new->discard[i][j]);
                }
            }
        }
    }

    int k;
    for(k = 0; k < old->numPlayers; k++)
    {
        if(k == player)
        {
            k++;
        }
        else
        {
            if(old->discardCount[k] != new->discardCount[k])
            {
                printf("Error: Expected %d ", old->discardCount[k]);
                printf(" handcount, had %d handcount \n", new->discardCount[k]);
            }
        }
    }

    if(old->playedCardCount == new->playedCardCount)
    {
        printf("Error: Expected change  to %d cards played", old->playedCards);
        printf(", had %d cards played \n", new->playedCards);
    }

}






void supplyIntToEnum(int supplyEnum)
{
    switch(supplyEnum)
    {
        case 0:
            printf("curse");
            break;

        case 1:
            printf("estate");
            break;

        case 2:
            printf("duchy");
            break;

        case 3:
            printf("province");
            break;

        case 4:
            printf("copper");
            break;

        case 5:
            printf("silver");
            break;

        case 6:
            printf("gold");
            break;

        case 7:
            printf("adventurer");
            break;

        case 8:
            printf("council_room");
            break;

        case 9:
            printf("feast");
            break;

        case 10:
            printf("gardens");
            break;

        case 11:
            printf("gardens");
            break;

        case 12:
            printf("mine");
            break;

        case 13:
            printf("remodel");
            break;

        case 14:
            printf("smithy");
            break;

        case 15:
            printf("village");
            break;

        case 16:
            printf("baron");
            break;

        case 17:
            printf("great_hall");
            break;

        case 18:
            printf("minion");
            break;

        case 19:
            printf("steward");
            break;

        case 20:
            printf("tribute");
            break;

        case 21:
            printf("ambassador");
            break;

        case 22:
            printf("cutpurse");
            break;

        case 23:
            printf("embargo");
            break;

        case 24:
            printf("outpost");
            break;

        case 25:
            printf("salvager");
            break;

        case 26:
            printf("sea_hag");
            break;

        case 27:
            printf("treasure_map");
            break;

    } //switch
}
