// 28123より大きい数は全て豊富数で表せる。28123以下の数の中で、豊富数で表せない数の和を求める。
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int i, j, sum=0, a[10000], c=0;
    long long int ans=0;

    for(i=0; i<10000; i++){ 
        a[i]=0;
    }

    // 豊富数を求める
    for(i=1; i<28123; i++){            // 割られるかず
        // printf("%d:",i);
        for(j=1; j<28123; j++){        // わる数
            if(i%j==0 && i!=j){
                sum+=j;
            }
        }
        // printf("%d\n", sum);
        if(sum>i){                     // 豊富数
            a[c]=i;
            c++;
        }else{
            ans+=i;
        }
        sum=0;
    }
    for(i=0; i<10000; i++){ 
        printf("%d,", a[i]);
    }
    printf("\n The answer is %lld\n", ans);
}
