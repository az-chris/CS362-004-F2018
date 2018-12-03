CFLAGS= -Wall -fpic -coverage -lm -std=c99
GCOVFLAGS = -fprofile-arcs -ftest-coverage

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

cardTest1: cardtest1.c dominion.o rngs.o
	gcc -o cardTest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

cardTest2: cardtest2.c dominion.o rngs.o
	gcc -o cardTest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

randomTest1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomTest1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

cardtestresults:  cardTest1 cardTest2 
	./cardTest1 > kruegercardtestresults.out
	./cardTest2 >> kruegercardtestresults.out
	gcov dominion.c >> kruegercardtestresults.out
	cat dominion.c.gcov >> kruegercardtestresults.out

randomtestresults: randomTest1 randomtestadventurer
	./randomTest1 &> kruegerrandomtestresults.out
	./randomtestadventurer >> kruegerrandomtestresults.out
	gcov dominion.c >> kruegerrandomtestresults.out
	cat dominion.c.gcov >> kruegerrandomtestresults.out

alltests: cardtestresults randomtestresults 

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player randomtestresults cardtestresults

clean:
	rm -f *.o playdom.exe playdom unit player player.exe    \
	unitTest1 unitTest2 unitTest3 unitTest4 badTestDrawCard \
	cardTest1 cardTest2 cardTest3 cardTest4 \
	*.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
