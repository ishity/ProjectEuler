// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.That is, 3 + 7 + 4 + 9 = 23.

//    3
//   7 4
//  2 4 6
// 8 5 9 3

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int a[4][4]={{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}}, b[8];
    // 2^3通りのルートがある
    int i, j, j2=0, j3=0, p, sum=0, c=0, ans=0, lar=0;

    // int a[15][15]={{75},{95,64},{17,47,82},{18,35,87,10},{20,4,82,47,65},{19,1,23,75,3,34},{88,2,77,73,07,63,67},{99,65,4,28,6,16,70,92},{41,41 ,26 ,56 ,83 ,40 ,80 ,70 ,33},{41 ,48 ,72 ,33 ,47 ,32 ,37 ,16 ,94 ,29},{53 ,71 ,44 ,65 ,25 ,43 ,91 ,52 ,97 ,51 ,14},{70 ,11 ,33 ,28 ,77 ,73 ,17 ,78 ,39 ,68 ,17 ,57},{91 ,71 ,52 ,38 ,17 ,14 ,91 ,43 ,58 ,50 ,27 ,29 ,48},{63 ,66 ,04 ,68 ,89 ,53 ,67 ,30 ,73 ,16 ,69 ,87 ,40 ,31},{4 ,62 ,98 ,27 ,23 ,9 ,70 ,98 ,73 ,93 ,38 ,53 ,60 ,4 ,23}};

    for(p=0; p<8; p++){
        b[p]=0;
    }

    for(i=0; i<4; i++){             // 行
        for(j=j3; j<j3+2; j++){     // 列、大きいものを求める
            if(a[i][j]>lar){
                lar=a[i][j];
                printf("%d&%d:%d, ", i,j,a[i][j]);
                j2=j;
            }
        }
        j3=j2;
        sum+=lar;
        lar=0;
    }
    b[0]=sum;

    for(i=0; i<4; i++){  
        for(j=0; j<4; j++){ 
            sum+=a[j][i];
        }
    }

    printf("The answer is %d\n", sum);
}
