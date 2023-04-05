// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int a=0, b=0, c=0, ans=0;
    for(a=1; a<999; a++){
        for(b=1; b<999-a; b++){
            c=1000-a-b;
            if(a*a+b*b==c*c){
                ans=a*b*c; 
                printf("a=%d, b=%d, c=%d\nThe product is %d\n",a,b,c,ans);
                break;
            }
        }
    }
}
