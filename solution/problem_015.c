// Starting in the top left corner of a 2×2 grid. There are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?
// 3x3は20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int ans=0, i,j;
    long long int a[21][21];

    // 初期化
    for(i=0; i<21; i++){
        for(j=0; j<21; j++){
            if(i==0 || j==0)a[i][j]=1;
            else a[i][j]=0;
        }
    }

    // 計算
    for(i=1; i<21; i++){
        for(j=1; j<21; j++){
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }

    // 確認出力
    for(i=0; i<21; i++){
        for(j=0; j<21; j++){
            printf("%d*%d:%lld\n",i,j,a[i][j]);
        }
    }

    printf("The answer is %lld\n", a[20][20]);
}