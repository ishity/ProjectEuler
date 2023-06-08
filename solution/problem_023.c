// 28123以下で、豊富数2つの和で表せない数の和を求める
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
// gcc problem_023.c -o problem_023

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 28123
#define aMAX 6965

// 豊富数かどうかの判定
bool abundant(int n){
    int sum=0;
    for(int i=0; i<n; i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum>n) return true;
    else return false;
}

// 配列にnが含まれているかどうかの判定
bool checkConsist(int *array, int n){
    int min=0, middle=6966/2, max=6965;
    while(middle!=min && middle!=max){
        if(n>array[middle]){
            min = middle;
            middle = (max+min)/2;
        }else if(n<array[middle]){
            max = middle;
            middle = (max+min)/2;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    int i, j, sum=0, a[10000], c=0, left;
    long long int ans=0;

    j=0;
    for(i=1; i<=MAX; i++){   
        if(abundant(i)){
            j++;
            // printf("%d:%d,\n", j,i);
            a[j] = i;
        }
    }

    for(i=0; i<MAX; i++){   // 28123以下の数について
        int num = i;
        for(j=1; j<=aMAX; j++){  // 配列のかず
            if(num>a[j]){
                left = num-a[j]; // 28123以下の数から豊富数を引いた数
                if(checkConsist(a, left)==true){ // 豊富数の和の時
                    num=0;
                    // printf(" 飽和数回避 ");
                    break;
                }
            } else {
                break;
            }
        }
        if(num!=0){
            ans+=i; 
            printf(" %dをたす \n", i);
        }
    }

    printf("\nThe answer is %lld\n", ans);
}
