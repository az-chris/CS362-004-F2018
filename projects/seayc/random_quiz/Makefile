testme: testme.c
	gcc -o testme testme.c

runTest: testme
	time ./testme 1 |tee testmeresults.out

clean:
	rm -f *.0 *.out testme
