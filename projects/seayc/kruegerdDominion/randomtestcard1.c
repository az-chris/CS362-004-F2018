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
    printf("**************    RANDOM TEST 1  *******************\n");
    printf("----------------------------------------------------\n");
    srand(time(NULL));   // Initialization, should only be called once.
    struct gameState Gs;
    struct gameState H;
    int loops = 500;
    int i;
     int card, choice1, choice2, choice3;
    int * bonus;
    card = 1;
    choice1 = 1;
    choice2 = 2;
    choice3 = 3;
    bonus = 0;

    for(i = 0; i < loops; i++)
    {   genRandDeck(&Gs);
        H = Gs;

        cardEffectSmithy(card, choice1, choice2, choice3, &Gs, 7, bonus);
        checkDeck(&H, &Gs, 1);
        if(Gs.handCount[1] == H.handCount[1]+3)
        {
            printf("Passed: Picked up 4 cards\n");
        }
        else if(Gs.deckCount[1] == 0 && Gs.handCount[1] >= H.handCount[1])
        {
            printf("Passed: Picked up maximum available cards\n");
        }
        else
        {
            printf("Failed: Expected %d cards, had %d cards\n", H.handCount[1]+3, Gs.handCount[1]);
        }
        if(Gs.deckCount[1] == H.deckCount[1]-4)
        {
            printf("Passed: Deck reduced by 4 cards\n");
        }
        else if(Gs.deckCount[1] == 0)
        {
            printf("Passed: Deck reduced by maximum available cards\n");
        }
        else
        {
            printf("Failed: Expected %d cards in deck, had %d cards\n", H.deckCount[1]-4, Gs.deckCount[1]);
        }
        Gs = EmptyGameState;
        H = EmptyGameState;
    }


    printf("----------------------------------------------------\n");
    printf("************    RANDOM CARD TEST 1  ****************\n");
    printf("****************************************************\n");
    printf("\n\n");

    return 0;
}

void genRandDeck(struct gameState *Gs)
{
    int RandomPlayers;
    RandomPlayers = RandomNumberInInterval(2, 4);
    Gs->numPlayers = RandomPlayers;
    // Curse
    Gs->supplyCount[0] = RandomNumberInInterval(10, 50);
    // estate
    Gs->supplyCount[1] = RandomNumberInInterval(10, 50);
    // duchy
    Gs->supplyCount[2] = RandomNumberInInterval(10, 50);
    // province
    Gs->supplyCount[3] = RandomNumberInInterval(10, 50);
    // copper
    Gs->supplyCount[4] = RandomNumberInInterval(10, 50);
    // silver
    Gs->supplyCount[5] = RandomNumberInInterval(10, 50);
    // gold
    Gs->supplyCount[6] = RandomNumberInInterval(10, 50);
    // adventurer
    Gs->supplyCount[7] = RandomNumberInInterval(10, 50);
    // council room
    Gs->supplyCount[8] = RandomNumberInInterval(10, 50);
    // feast
    Gs->supplyCount[9] = RandomNumberInInterval(10, 50);
    // gardens
    Gs->supplyCount[10] = RandomNumberInInterval(10, 50);
    // mine
    Gs->supplyCount[11] = RandomNumberInInterval(10, 50);
    // remodel
    Gs->supplyCount[12] = RandomNumberInInterval(10, 50);
    // smithy
    Gs->supplyCount[13] = RandomNumberInInterval(10, 50);
    // village
    Gs->supplyCount[14] = RandomNumberInInterval(10, 50);
    // baron
    Gs->supplyCount[15] = RandomNumberInInterval(10, 50);
    // great hall
    Gs->supplyCount[16] = RandomNumberInInterval(10, 50);
    // minion
    Gs->supplyCount[17] = RandomNumberInInterval(10, 50);
    // steward
    Gs->supplyCount[18] = RandomNumberInInterval(10, 50);
    // tribute
    Gs->supplyCount[19] = RandomNumberInInterval(10, 50);
    // ambassador
    Gs->supplyCount[20] = RandomNumberInInterval(10, 50);
    // cutpurse
    Gs->supplyCount[21] = RandomNumberInInterval(10, 50);
    // embargo
    Gs->supplyCount[22] = RandomNumberInInterval(10, 50);
    // outpost
    Gs->supplyCount[23] = RandomNumberInInterval(10, 50);
    // salvager
    Gs->supplyCount[24] = RandomNumberInInterval(10, 50);
    // sea_hag
    Gs->supplyCount[25] = RandomNumberInInterval(10, 50);
    // treasure_map
    Gs->supplyCount[26] = RandomNumberInInterval(10, 50);

    int i;
    for(i = 0; i < treasure_map+1; i++)
    {
        Gs->embargoTokens[i] = RandomNumberInInterval(0, 5);
    }

    Gs->outpostPlayed = RandomNumberInInterval(0, 2);

    Gs->outpostTurn = RandomNumberInInterval(0, RandomPlayers);

    Gs->whoseTurn = RandomNumberInInterval(0, RandomPlayers);

    Gs->numActions = RandomNumberInInterval(1, 10);

    Gs->coins = RandomNumberInInterval(0, 100);

    Gs->numBuys = RandomNumberInInterval(1, 10);

    int j;
    int k;
    for(j = 0; j < treasure_map+1; j++)
    {
        for(k = 0; k < RandomPlayers; k++)
        {
            int temp_card;
            temp_card = RandomNumberInInterval(0, 20);
            if(Gs->supplyCount[j] >= temp_card)
            {
                Gs->hand[k][j] = temp_card;
                Gs->supplyCount[j] -= temp_card;
            }
            else
            {
                Gs->hand[k][j] = 0;
            }
        }
    }

    int p;
    for(p = 0; p < RandomPlayers; p++)
    {
        int pk;
        for(pk = 0; pk < treasure_map+1; pk++)
        {
            Gs->handCount[p] += Gs->hand[p][pk];
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
            if(Gs->supplyCount[jj] >= temp_card)
            {
                Gs->deck[kk][jj] = temp_card;
                Gs->supplyCount[jj] -= temp_card;
            }
            else
            {
                Gs->deck[kk][jj] = 0;
            }
        }
    }

    int ii;
    for(ii = 0; ii < RandomPlayers; ii++)
    {
        int iz;
        for(iz = 0; iz < treasure_map+1; iz++)
        {
            Gs->handCount[ii] += Gs->hand[ii][iz];
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
            if(Gs->supplyCount[a] >= temp_card)
            {
                Gs->deck[b][a] = temp_card;
                Gs->supplyCount[a] -= temp_card;
            }
            else
            {
                Gs->deck[b][a] = 0;
            }
        }
    }

    int c;
    for(c = 0; c < RandomPlayers; c++)
    {
        Gs->deckCount[c] = RandomNumberInInterval(0, 200);
    }



    int d;
    int e;
    e = RandomNumberInInterval(0, MAX_DECK);
    for(d = 0; d < e; d++)
    {
        Gs->playedCards[d] = RandomNumberInInterval(0, 26);
    }

    Gs->playedCardCount = RandomNumberInInterval(0, e);

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

    if(old->outpostPlayed != new->outpostPlayed)
    {
        printf("Error: Expected %d outposts played", old->supplyCount[a]);
        printf(", had %d outposts played \n", new->supplyCount[a]);
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
