// reads doubles 

#include "read_input.h" 
#include <math.h>



int read_real(char* digits,int n, double* num)
{

  if(is_valid_double(digits)){
    if(digits[0] == '-')
      *num = -convert_to_double(digits + 1);
    else if(digits[0] == '+') 
      *num = convert_to_double(digits + 1);
    else
      *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}


int is_valid_double(const char* digits)
{
  int valid = 1;
  int i;
  int decimal =0;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
	  if(digits[i] < '0' ||  digits[i] > '9'){
	    if (digits[i] == '.') {
	     decimal++;
	    } else {
          valid = 0;
	      }
	  }
      i++;
    }
   if (decimal ==0 || decimal > 1) {
	  valid =0;
   }else {
	valid =1;
   }
  
  return valid;
}


double convert_to_double(const char* digits)
{
  double sum = 0;
  int i = 0;
  double x =0;
  
 while(digits[i] != '\0') {
   if (digits[i] == '.') {
    x=i+1;
   }else {
    sum = 10 * sum + (digits[i] - '0');
    }
  i++;
 }
 
 x = i-x;
 x = pow(10,x);
 sum = sum/x;
 return sum;
}
