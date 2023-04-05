// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10 001st prime number?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 200000

int main(){
  int i, j, num=2, jud=0;
  int p[20000];
  p[0]=2;
  p[1]=3;
  for(i=4; i<MAX; i++){      // 割られる数
    for(j=2; j<MAX; j++){    // 割る数
      if(i>j){
        if(i%j==0){
          jud=0;
          break;
        }
        else jud=1;
      }else break;
    }
    if(jud==1){
      p[num]=i;
      printf("%d:%d,\n",num,p[num]);
      num++;
      jud=0;
    }
  }
  printf("The 10001th prime num is %d\n", p[10000]);
}


// how do i define the MAX number?
// The 10001th prime num is 104743
