// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int i=0, j=0, p[500], q=0, k[500];
    long long int ans=0;

    // 初期化
    for(i=0; i<500; i++){
        p[i]=0;
        k[i]=0;
    }
    p[499]=1;

    for(j=0; j<1000; j++){          // 2を1000回かける
        //配列の桁数でどこまで二をかけるのかを判断
        for(i=499; i>0; i--){
            q=0;
            p[i]*=2;
            if(p[i]>=10 && p[i]<50){
                q=p[i]%10;      // 1のくらい
                k[i-1]+=p[i]/10;     // 繰り上がり
                p[i]=q;
            }else{
                q=p[i]%10;      // 1のくらい
                k[i-1]+=p[i]/10;     // 繰り上がり
                k[i-2]+=p[i]/100;    // 繰り上がり
                p[i]=q;
            }
        }
        printf("\n計算結果は\n");

        for(i=499; i>0; i--){     // 繰り上がりの処理
            p[i]+=k[i];
            k[i]=0;
        }
        for(i=0; i<500; i++){     // 出力
            printf("%d",p[i]);
        }
        printf("\n");
    }

    // 全ての桁を足し合わせる
    for(i=0; i<500; i++){
        ans+=p[i];
    }
    printf("The sum of the digits of the number 2^1000 is %lld\n", ans);

}