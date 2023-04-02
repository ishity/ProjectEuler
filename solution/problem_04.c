// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000000

int main(){
    int ans=0, num=0, product1=0, product2=0, i, j, k, *p, q[MAX];
    for(i=100; i<1000; i++){
        for(j=100; j<1000; j++){
            num=i*j;
            // printf("%d,",num);
            if(num<100000){ // 5桁以下
                q[0]=num%10;                        // 1の位
                q[1]=(num%100-q[0])/10;             // 10の位
                q[2]=num/10000;                     // 10000の位
                q[3]=num/1000-(q[2]*10);            // 1000の位

                // ----------格桁の出力----------
                // printf("%d=",num);
                // printf("%d",q[0]);
                // printf("%d",q[1]);
                // printf("%d",q[2]);
                // printf("%d\n",q[3]);
                // ----------------------------

                if(ans<num && q[0]==q[2] && q[1]==q[3]){
                    ans=num;
                    product1=i;
                    product2=j;
                }
            }else{          // 6桁以上
                q[0]=num%10;                        // 1の位
                q[1]=(num%100-q[0])/10;             // 10の位
                q[2]=(num%1000-num%100)/100;        // 100の位
                q[3]=num/100000;                    // 100000の位
                q[4]=num/10000-q[3]*10;             // 10000の位
                q[5]=num/1000-(q[3]*100+q[4]*10);   // 1000の位

                // ----------格桁の出力----------
                // printf("%d=",num);
                // printf("a%d",q[0]);
                // printf("b%d",q[1]);
                // printf("c%d",q[2]);
                // printf("d%d",q[3]);
                // printf("e%d",q[4]);
                // printf("f%d\n",q[5]);
                // ----------------------------

                if(ans<num && q[0]==q[3] && q[1]==q[4] && q[2]==q[5]){
                    ans=num;
                    product1=i;
                    product2=j;
                }
            }
        }
    }
    printf("The largest palindrome %d made from %d and %d\n", ans, product1, product2);
}
