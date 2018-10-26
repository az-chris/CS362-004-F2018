To compile the program simply use: make runTest
This will run the file, time its execution, and produce a file with the results.

To remove all associated files simply run: make clean

This program can run the test with 4 different sets of arrays.  This is set in
the makefile on line 5 after "/testme" and before "|tee". Simply change the 1 to
1-4 which corresponds to an array from below:


Array Set 1 - Maximizes performance by using smallest possible arrays. These
              arrays only contain values that each sections is looking for
Array Set 2 - Combines the two small arrays into one larger array.

**************************************************************
*************************  WARNING   *************************
*******  this array set may exceed 5 min max run time  *******
**************************************************************
Array Set 3 - Contains all lowercase a-z characters and required brackets

**************************************************************
*************************  WARNING   *************************
***  this array set will likely exceed 5 min max run time  ***
**************************************************************
Array Set 4 - Contains all A-Z and a-z characters and required brackets
