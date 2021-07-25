#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char *argv[])
{
  int m = 0;

  // if argument number is incorrect output this notice
  if (argc != 2) 
  {
    printf("Incorrect number of arguments provided.\n");
    return 0;
  }

  // read in ints one at a time and multiply by the 2nd argv value
  while (scanf("%d", &m) != EOF) 
  {
    printf("%d\n", multiply(m, atoi(argv[1])));
  }

  return 0;
}
