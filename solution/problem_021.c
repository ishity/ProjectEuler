// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

// Evaluate the sum of all the amicable numbers under 10000.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int i,j, sum=0, c=0, n=0, m=0;
    int a[10000][2];

    // 訳すうを足す
    for(i=1; i<10000; i++){            // 割られるかず
        printf("%d:", i);
        for(j=1; j<10000; j++){        // わる数
            if(i%j==0 && i!=j){
                printf("%d,", j);
                sum+=j;
            }
        }
        printf("=%d\n", sum);
        a[c][0]=i;
        a[c][1]=sum;
        c++;
        sum=0;
    }

    sum=0;
    // search amicable numbers
    for(i=1; i<10000; i++){
        n = a[i][0];
        m = a[i][1];
        for(j=1; j<10000; j++){ 
            if(n==a[j][1] && m== a[j][0] && n!=m){
                printf("%d,%d\n", n,m);
                sum+=(n+m);
            }
        }
    }
    printf("The answer is %d\n", sum/2);
}