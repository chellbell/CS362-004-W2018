#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // generate a random integer.
    // when saved to a char variable, it is parsed as ascii character.
    // limit the available charset to #27 through #126.
    return ((random() % 99) + 27);
}

char *inputString()
{
    // random string to generate to pass test case is 5 chars long.
    int strLength = 5;
    char * randString = malloc(sizeof(char) * strLength);
    // to pass the test these chars have to appear in a specific order eventually.
    // so don't use more chars and actually be random b/c it will crash terminal.
    char * testCharacters = "erst";

    // fill the random string randomly.
    for (int i = 0; i < strLength; i++) {
        randString[i] = testCharacters[rand() % 4];
    }
    
    return randString;
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
    if (c == ' ' && state == 3) state = 4;
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
    testme();
    return 0;
}
