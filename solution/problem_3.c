// The prime factors of 13195 are 5, 7, 13 and 29.

// What is the largest prime factor of the number 600851475143 ?

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
// #define MAX 600851475143

int main(){
    unsigned long long int max=0, i=0;
    int k=0, ans=0;

    max = 600851475143;
    int j[10000];

    // 因数を配列に格納
    while(i < max){
        if(max%i==0){
            j[k]=i;
            i++;
            k++;
        }
        i++;
    }
    printf("b\n");
    for(int m=k-1; m>=0; m--){
        for(int l=0; l<k; l++){
            if(j[m]>j[l] && j[m]%j[l]==0){
                j[m]/=j[l];
            }
        }
    }
    for(int m=0; m<k; m++){
        if(j[m]>ans) ans=j[m];
    }
    printf("The largest prime factor is %d\n", ans);
}