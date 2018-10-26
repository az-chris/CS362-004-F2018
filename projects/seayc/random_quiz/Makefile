testme: testme.c
	gcc -o testme testme.c

runTest: testme
	time ./testme 2 |tee testmeresults.out

clean:
	rm -f *.0 *.out testme
