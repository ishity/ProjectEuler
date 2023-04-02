// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 2000000

int main(){
    long long int ans=0; 
    int jud=0;
    for(int i=2; i<MAX; i++){      // 素数の候補
        for(int j=2; j<i; j++){    // 素数かどうか確かめる
            if(i%j==0){
                jud=1;
                break;
            }
        }
        if(jud==0){
            printf("%d,", i);
            ans+=i;
        }
        jud=0;
    }
    printf("%lld,", ans);
}