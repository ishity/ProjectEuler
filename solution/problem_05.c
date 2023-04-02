// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int i, j=1, jud=0, ans=0;
    while(jud!=1){
        ans=j;
        for(i=1; i<=20; i++){
            printf("j: %d\n", j);
            if(j%i!=0){
                break;
            }
            if(i==20 && j%i==0){
                jud=1;
            }
            j=ans;
        }
        j++;
    }
    printf("The smallest positive number that is evenly divisible by all of the numbers from 1 to 20: %d\n", ans);
}


// It takes too long to calculate.;;
// The smallest positive number that is evenly divisible by all of the numbers from 1 to 20: 232792560
