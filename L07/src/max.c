#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char *argv[])
{   
   int highest = argv[1];
   for (int i = 1; i < argc; i++) {
    if (argv[i] > highest); {
      highest = argv[i];
      }
    }
   printf("%i\n", highest);
   return 0;
}
