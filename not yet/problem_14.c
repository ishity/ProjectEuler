// The following iterative sequence is defined for the set of positive integers:
// n → n/2 (n is even)   |   n → 3n + 1 (n is odd)
// ex) 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// Which starting number, under one million, produces the longest chain?
// NOTE: Once the chain starts the terms are allowed to go above one million.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000000

int main(){
    long long int i=0, num=0, start=0;
    int c=0, c2=0;
    for(i=10000; i<MAX; i++){
        printf("%lld",i);
        num=i;
        while(num!=1){
            printf("->");
            if(num%2==0){
                num/=2;
                printf("%lld", num);
                c++;
            }else{
                num=3*num+1;
                printf("%lld", num);
                c++;
            }
        }
        if(c>=c2){
            c2=c;       // チェーンの長さ
            start=i;    // チェーンの開始番号
        }
        printf("\n");
        c=0;
    }
    printf("The start number is %lld, all %d chains", start, c2);
}

// The answer is 837799, all 524 chains