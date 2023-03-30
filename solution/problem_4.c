// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000000

int main(){
    int ans=0, i, j, *p, q[MAX];
    for(i=1; i<10; i++){
        for(int j=1; j<10; j++){
            ans=i*j;
            p=&ans;
            printf("%d\n", *p);
        }
    }
    // for(i=0; i<MAX; i++){
    //     while()
    // }
}