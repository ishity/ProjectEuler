// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, j, keta[100], lar=1;
    double q, k, d=10.0;

    for(i=2; i<=10; i++){
        q = 1.0/(double)i;
        
        // 少数第2位
        k = q * 10.0; // 10^-1の位の数を見る
        keta[0] = (int)k;

        // 少数第2位
        k = (k - (double)keta[0])* 100.0;
        keta[1] = (int)k;

        if(keta[0]==keta[1]){
            for(j=1; j<10; j++){
                keta[j+1] = (k - (double)keta[0]) * d; // 次の桁
                if(keta[0] != keta[j+1]) break;
            }
        } else {
            for(j=1; j<10; j++){
                keta[j+1] = (k - (double)keta[0]) * d; // 次の桁
                if(keta[0] == keta[j+1]){
                    for(k=j+1; k<j; k++){
                        if(keta[k] != keta[k+1]) break;
                    }
                }
            }
        }

        printf("%d:%f,%f, keta:%d,%d\n", i,q,k, keta[0], keta[1]);
    }
}