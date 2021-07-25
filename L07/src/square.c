#include <stdio.h>
#include "library.h"

int main(int argc, area)
{ 
   printf("Enter the side of square: ");
   scanf("%d", &argc);
   //area
   area = argc * argc;

   printf("Area of the square: %d", area);
   return 0;

}
