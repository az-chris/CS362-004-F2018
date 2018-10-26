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

unitTest1: unittest1.c dominion.o rngs.o
	gcc -o unitTest1  unittest1.c -g dominion.o rngs.o  $(CFLAGS) $(GCOVFLAGS)

unitTest2: unittest2.c dominion.o rngs.o
	gcc -o unitTest2 unittest2.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

unitTest3: unittest3.c dominion.o rngs.o
	gcc -o unitTest3 unittest3.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

unitTest4: unittest4.c dominion.o rngs.o
	gcc -o unitTest4 unittest4.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

cardTest1: cardtest1.c dominion.o rngs.o
	gcc -o cardTest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

cardTest2: cardtest2.c dominion.o rngs.o
	gcc -o cardTest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

cardTest3: cardtest3.c dominion.o rngs.o
	gcc -o cardTest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

cardTest4: cardtest4.c dominion.o rngs.o
	gcc -o cardTest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS) $(GCOVFLAGS)

unittestresults: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4
	./unitTest1 &> unittestresults.out
	./unitTest2 >> unittestresults.out
	./unitTest3 >> unittestresults.out
	./unitTest4 >> unittestresults.out
	./cardTest1 >> unittestresults.out
	./cardTest2 >> unittestresults.out
	./cardTest3 >> unittestresults.out
	./cardTest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom unit player player.exe    \
	unitTest1 unitTest2 unitTest3 unitTest4 badTestDrawCard \
	cardTest1 cardTest2 cardTest3 cardTest4 \
	*.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
