/* prog_one.c
 * ENSF 337 Fall 2020 Lab 4 Exercise  E
 *
 */

#include <stdio.h>
#include <limits.h>
#include "read_input.h"

#define SIZE 50

int main(void)
{
  int n = 0;
  double k=0;
  
  char digits[SIZE];  

  int y = EOF;
  int dy = EOF;
  
while (1)
{
      printf("\n\nEnter an integer or press Ctrl-D to quit: ");
      y = read_integer(digits, SIZE, &n); 

      if(y == 1)
	printf("\nYour integer value is: %d", n);
      else if(y == EOF){
	printf("\nGood Bye.\n");
	break;
      }
  else {
	 printf("\n%s is an invalid integer.", digits);
   k = n;
   y = read_real(digits, SIZE, &k);  

   //checking if it's a double instead 
   if(y == 1)
	 printf("\nYour double value is: %lf", k);
    else
	   printf("\n%s is an invalid double.", digits);
  }

}    
  return 0;
}
