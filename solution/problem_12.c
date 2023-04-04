// What is the value of the first triangle number to have over five hundred divisors?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100000

int main(){
int num=1, c=0, c2=0;
int p[MAX];

// Show triangle numbers
for(int i=2; i<MAX; i++){
    // printf("%d,",num);
    p[c]=num;
    num+=i;

    // 約数の個数を求める
    printf("%d:", p[c]);
    for(int i=1; i<=p[c]; i++){
        if(p[c]%i==0){      // 割り切れた場合
            c2++;           // c2に割り切れた回数を記録
            // printf("%d,", i);
            if(c2>500){     // 500個以上の約数を持つ場合はforを抜ける
                break;
            }
        }
    }
    if(c2>500) break; // 500個以上の約数を持つ場合はforを抜ける
    else{
        printf("%d個,end\n", c2);
        c2=0; // c2をリセット
        c++;
    }
}
printf("The answer is %d\n", p[c]);
}


// c--;
// printf("c:%d,", c);
// printf("%d\n", p[c]);

// divisors
// while(c>0){
//     printf("%d:", p[c]);
//     for(int i=1; i<=p[c]; i++){
//         if(p[c]%i==0){
//             c2++; // 割り切れる
//             // printf("%d,", i);
//             if(c2>500){
//                 break;
//             }
//         }
//     }
//     if(c2+1>500) break;
//     c--;
//     printf("%d個,end\n", c2);
//     c2=0;
// }
// printf("The answer is %d\n", p[c]);
// }
