// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
// 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)contains 20 letters.
// 1~9, 11~19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long long int a=0;
    int i, j, num[10], size=0, size2=0, size3=0;
    char numbers[101][10]={"and","one","two","three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "","","","","","","","","", "thirty", "","","","","","","","","","forty", "","","","","","","","","", "fifty", "","","","","","","","","", "sixty", "","","","","","","","","","seventy", "","","","","","","","","","eighty", "","","","","","","","","","ninety", "","","","","","","","","","hundred"};
    // [個数][文字数]

    printf("%s\n", numbers[100]);

    for(i=1; i<1001; i++){
        // xは1の位、yは10の位、zは100の位
        int x=i%10, y=(i/10)%10, z=i/100, t=i/1000;
        if(t!=0){                                   // 1000の時
            size = strlen(numbers[1])+8;
            a+=size;
            printf("%d=%s thousand,%d--%lld\n", i, numbers[1], size,a);
        }else{
            if(z==0){                               // 100未満
                if((x!=0 && y==0)||(x==0 && y!=0)||(y==1)){ // 1,2,3,....9 || 10,20,30,...90
                    size = strlen(numbers[i]);
                    a+=size;
                    printf("%d=%s,%d--%lld\n", i, numbers[i],size,a);
                }else{
                    size = strlen(numbers[x]);
                    size2 = strlen(numbers[y*10]);
                    a+=size;
                    a+=size2;
                    printf("%d=%s %s,%d--%lld\n", i, numbers[y*10], numbers[x], size+size2,a);
                }
            }else{                                  //100以上
                if(x==0&&y==0&&z!=0){               // 100の時
                    size = strlen(numbers[z]);
                    size2 = strlen(numbers[100]);
                    a+=size;
                    a+=size2;
                    printf("%d=%s %s,%d--%lld\n", i, numbers[z],numbers[100],size+size2,a);
                }else{
                    if((x!=0 && y==0)||(x==0 && y!=0)||(y==1)){ 
                        // 1,2,3,....9 || 10,20,30,...90
                        size = strlen(numbers[i%100]);
                        size3 = strlen(numbers[z])+strlen(numbers[100]);
                        a+=size;
                        a+=(size3+3);
                        printf("%d=%s %s and %s,%d--%lld\n", i,numbers[z],numbers[100],numbers[i%100],size+size3+3,a);
                    }else{
                        size = strlen(numbers[x]);
                        size2 = strlen(numbers[y*10]);
                        size3 = strlen(numbers[z])+strlen(numbers[100]);
                        a+=size;
                        a+=size2;
                        a+=(size3+3);
                        printf("%d=%s %s and %s %s,%d--%lld\n", i, numbers[z],numbers[100],numbers[y*10], numbers[x], size+size2+size3+3,a);
                    }
                }
                
            }
        }   
    }
    printf("The answer is %lld\n", a);
}
