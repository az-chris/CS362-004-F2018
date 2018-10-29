#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CHARS  10
#define MAX_STRING  5
#define MAX_INPUT 13
#define MAX_PAIN 61
#define LOWER_INPUT 35

char charInputs []  = { '[' , '(' , '{' , ' ', 'a' , 'x' , '}' , ')' ,
                        ']' , '\0'};

char stringInputs[] = { 'r' , 'e' , 's', 't' , '\0' };

char totalInputs[] ={'[' , '(' , '{' , ' ', 'a' , 'x' , '}' , ')' ,
                    ']' , 'r' , 'e' , 's', 't' , '\0'};

char maxInputs[] =  {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' ,
                     'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' ,
                     'u' , 'v' , 'w' , 'x' , 'y' , 'z' , 'A' , 'B' , 'C' , 'D' ,
                     'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' ,
                     'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' ,
                     'Y' , 'Z' , '[' , '(' , '{' , ' ' , 'a' , 'x' , '}' , ')' ,
                     ']' , '\0' };
char lowInputs[] =  {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' ,
                     'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' ,
                     'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '[' , '(' , '{' , ' ' ,
                     'a' , 'x' , '}' , ')' , ']' , '\0' };
int argumentSet;

char inputChar()
{
    // TODO: rewrite this function
    char c;
    int r;
    if(argumentSet == 1)
    {
        r = rand() % MAX_CHARS;
        c = charInputs[r];
    }
    else if(argumentSet == 2)
    {
        r = rand() % MAX_INPUT;
        c = totalInputs[r];
    }
    else if(argumentSet == 3)
    {
        r = rand() % LOWER_INPUT;
        c = lowInputs[r];
    }
    else
    {
        r = rand() % MAX_PAIN;
        c = maxInputs[r];
    }

    return c;
}

char *inputString()
{
    char *s = malloc(MAX_STRING);
    int i;
    for(i = 0; i < MAX_STRING ; i++)
    {
        if( argumentSet != 1)
        {
            s[i] = inputChar();
        }
        else
        {
            int r = rand() % MAX_STRING;
            s[i] = stringInputs[r];
        }
    }
    s[MAX_STRING] = '\0';
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int i;
    for(i = 0; i < argc ; i++)
    {
        printf("%s \n",argv[i]);
    }
    if(argc == 1)
    {
        argumentSet = 1;
    }
    else
    {
        argumentSet = atoi(argv[1]);
        printf("argumentSet = %d\n", argumentSet);
    }

    testme();
    return 0;
}
