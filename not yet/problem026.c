// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkCycle (double num, int* k, int* hantei2, int* count2) { 
    // kは繰り返すかもしれないdigit, numは
    int i=0;
    double num2;

    while(k[i] != '\0'){
        num = (num - (double)k[0]) * 10.0;
        if(k[i] != (int)num){
            *hantei2=1;
            break;
        }
        i++;
    }
    *count2 = i;
}

int main(){
    int i, j, keta[100], lar=1, hantei=0, count=0;
    double q, k, d=10.0;

    for(i=2; i<=10; i++){
        q = 1.0/(double)i;
        
        // 少数第1位
        k = q * d; // 10^-1の位の数を見る
        keta[0] = (int)k;

        // 少数第2位
        k = (k - (double)keta[0])* d;
        keta[1] = (int)k;

        if(keta[0]==keta[1]){ // 1文字サイクル
            for(j=2; j<10; j++){ // 10回続くか確かめる
                k = (k - (double)keta[0]) * d;
                keta[j] = (int)k; // 次の桁
                if(keta[0] != keta[j]){
                    hantei=1;
                    break;
                }
            }
            if(hantei==0){
                printf("one digit cycle -- ");
            } else {
                printf("not 1 digit cycle -- ");
            }
            hantei=0;
        } else { // 複数文字サイクル
            for(j=2; j<10; j++){ // keta[0]がもう一回出るまでketaに格納
                k = (k - (double)keta[0]) * d;
                keta[j] = (int)k; // 次の桁
                if(keta[0] == keta[j]){ // keta[0]が~keta[j]まで繰り返しているかみる
                    // ketaがその後繰り返されるかみる
                    printf(" 関数　");
                    checkCycle(k, keta, &hantei, &count);
                    if(hantei==0){ // 繰り返していることがわかった
                        printf("some digit cycle: %d-- ", count);
                    } else { // 繰り返していない
                        printf("not some digit cycle -- ");
                    }
                } 
            }
            if(hantei==0){ // 繰り返していることがわかった
                printf("not some digit cycle -- ");
            }
        }
        printf("%d:%f, keta:%d,%d\n", i,q, keta[0], keta[1]);
    }
}