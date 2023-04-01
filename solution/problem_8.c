// The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100000

int main(){
    char str[30][60];
    int num=0, c=0;
    long long int ans1=1, ans2=1;

    // 一行の数字を文字列として読み込む
    printf("入力してください。\n");
    while(c<20){
        for(int i=0; i<20; i++){
            for(int j=0; j<51; j++){ 
                scanf("%c", &str[i][j]);
            }
            c++;
        }
    }

    // 読み込んだ文字列を表示
    // for(int i=0; i<20; i++){
    //     for(int j=0; j<51; j++){ 
    //         printf("%c", str[i][j]);
    //     }
    // }
    
    c=0;
    while(c<20){                        // 文字列の中から13個の数字を取り出して計算
        printf("%d行目\n", c);
        for(int i=0-c; i<38-c; i++){    // 50列の数字のうち、
            for(int j=0; j<13; j++){    // 13個の数字を取り出す
                char p;
                char *samp;
                p=str[c][i+j+c];        // 1文字ずつ取り出す
                samp = &p;              // 取り出したもののアドレスをsampに代入
                num = atoi(samp);       // sampのアドレスの中身をint型に変換
                printf("%d,", num);
                ans1*=num;              // 取りだした数字を掛け合わせる
            }
            printf(":%lld\n", ans1);
            if(ans1>ans2) ans2=ans1;
            else ans2=ans2;
            ans1=1;
        }
        c++;                            // 1行読み込んだら、次の行を読み込む
    }
    printf("The largest product is %lld\n", ans2);
}


