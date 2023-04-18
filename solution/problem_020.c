//　n! means n × (n − 1) × ... × 3 × 2 × 1
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
// Find the sum of the digits in the number 100!

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int i, j, n=0, m=0, ans=0, b[200], c[200]; // [個数][文字数]

    // 階上の計算
    for(i=0; i<200; i++){
        b[i]=0;
        c[i]=0;
    }
    b[199]=1;
    for(i=100; i>=1; i--){            // かける数
        printf("%d:\n",i);
        for(j=0; j<200; j++){        // かけられる数
            printf("%d",b[j]);
            n=b[j]*i;
            if(n<10) b[j]=n;
            else{
                b[j]=n%10;    // 1の位
                c[j-1]=n/10;  // 繰り上がり
            }
        }
        for(j=0; j<200; j++){
            m = b[j]+c[j];
            if(m>=10){
                b[j]=m%10;
                b[j-1]+=(m/10);
            }else{
                b[j]+=c[j];
            }
            c[j]=0;
        }
        printf("\n");
    }

    // 各桁の和を求める
    for(i=0; i<200; i++){
        ans+=b[i];
    }
    printf("The answer is %d\n", ans);
}