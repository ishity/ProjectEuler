// the squares of the first one hundred natural numbers and the square of the sum.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
  int i, sum1=0, sum2=0, sum3=0, ans=0;
  //  The sum of the squares of the first one hundred natural numbers
  for(i=1; i<=100; i++){
    sum1+=i*i;
  }
  printf("The sum of the squares of the first one hundred natural numbers is %d\n", sum1);

  // The square of the sum of the first one hundred natural numbers
  for(i=1; i<=100; i++){
    sum2+=i;
  }
  printf("The sum fo the one hundred natural numbers is %d\n", sum2);
  sum3=sum2*sum2;
  printf("The square of the sum of the first one hundred natural numbers is %d\n", sum3);
  
  ans=sum3-sum1;
  
  printf("The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is %d\n", ans);
}
