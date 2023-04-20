// The 12th term, F12, is the first term to contain three digits.
// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

//F1 = 1
// F2 = 1
// F3 = 2
// F4 = 3
// F5 = 5
// F6 = 8
// F7 = 13
// F8 = 21
// F9 = 34
// F10 = 55
// F11 = 89
// F12 = 144

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZEY 5000   /* 行数 */
#define SIZEX 1000    /* 1行あたりの文字数 */

int main(){
    int i,j, m, p=0, q=0,r=0, k[1000];
    int (*f)[SIZEX];   // arrはchar[SIZEX]へのポインター
    // char[SIZEX]へのポインターなので、SIZEY * char[SIZEX]分確保
    f = malloc(sizeof(int) * SIZEY * SIZEX);

    for(i=0; i<SIZEY; i++){
        for(j=0; j<1000; j++){
            f[i][j]=0;
            if(i==0)k[j]=0;
        }
    }

    // フィボナッチ数列を作る
    f[0][999]=1;
    f[1][999]=1;

    // 桁に気をつけて計算をする
    for(i=2; i<SIZEY; i++){         // 行
        for(j=999; j>=0; j--){     // 足した数を繰り上がり用の配列に入れる
            k[j]=f[i-1][j]+f[i-2][j];
        }
        for(j=999; j>=0; j--){     // 列
            if(k[j]>=10){
                p=k[j]/10; // 10の位
                q=k[j]%10; // 1の位
                f[i][j]+=q;
                f[i][j-1]+=p;
            }else{
                f[i][j]+=k[j];
            }
        }
        if(k[0]!=0){
            r=i;
            break;
        }
    }

    for(i=0; i<SIZEY; i++){
        printf("%d:",i);
        for(j=0; j<1000; j++){
            printf("%d", f[i][j]);
        }
        printf("\n");
        printf("\n");
    }
    printf("The answer is %d\n", r);
    free(f);
}