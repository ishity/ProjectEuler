// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
// スタート 2,10,26,50.....
// a : 2+1, 10+3,  26+5,  50+7 (2)
// b : 2+3, 10+7,  26+11, 50+15 (4)
// c : 2+5, 10+11, 26+17, 50+23 (6)
// c : 2+7 ,10+15, 26+23, 50+31 (8)
// 1,3,5...1001 -> 1,2n+1, 2n+2.....2*500+1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main (){
    long long int a=0,b=0,c=0,d=0, sum=0;
    int i,j, base=2;

    for(i=1; i<=500; i++){
        a += (base+2*i-1);
        b += (base+4*i-1);
        c += (base+6*i-1);
        d += (base+8*i-1);
        base += (8*i);
    }

    printf("a: %lld, b: %lld, c: %lld, d: %lld\n", a,b,c,d);
    sum = a+b+c+d+1;
    printf("The answer is %lld\n", sum);
}

// gcc problem028.c -o problem028

