// Starting in the top left corner of a 2×2 grid. There are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?
// 3x3は20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int ans=0, i,j, a[21][21];

    for(i=0; i<21; i++){
        for(j=0; j<21; j++){
            if((i==20 && j==20)||(i==0 && j==0)) ans+=0;
            else if(j==20 || i==20){
                if(j==0||i==0) ans+=1;
                else ans*=1;
            }
            else if(i==0 || j==0) ans+=1;
            else ans+=2;
        }
    }

    printf("%d\n", ans);
}