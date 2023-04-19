// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.That is, 3 + 7 + 4 + 9 = 23.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    //int a[4][4]={{3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}};
    // 2^3通りのルートがある
    int i, j, sum=0, ans=0, b[6], c=0, c2=3;

    int a[15][15]={{75},{95,64},{17,47,82},{18,35,87,10},{20,4,82,47,65},{19,1,23,75,3,34},{88,2,77,73,07,63,67},{99,65,4,28,6,16,70,92},{41,41 ,26 ,56 ,83 ,40 ,80 ,70 ,33},{41 ,48 ,72 ,33 ,47 ,32 ,37 ,16 ,94 ,29},{53 ,71 ,44 ,65 ,25 ,43 ,91 ,52 ,97 ,51 ,14},{70 ,11 ,33 ,28 ,77 ,73 ,17 ,78 ,39 ,68 ,17 ,57},{91 ,71 ,52 ,38 ,17 ,14 ,91 ,43 ,58 ,50 ,27 ,29 ,48},{63 ,66 ,04 ,68 ,89 ,53 ,67 ,30 ,73 ,16 ,69 ,87 ,40 ,31},{4 ,62 ,98 ,27 ,23 ,9 ,70 ,98 ,73 ,93 ,38 ,53 ,60 ,4 ,23}};

    // 下から数字を足していくよ
    for(i=14; i>=0; i--){        // 一番上の行まで回す
        for(j=0; j<i; j++){     // 和の配列に代入する
            if(a[i][j]>a[i][j+1]){   // 一回のみ代入
                a[i-1][j]+=a[i][j];
            }else{
                a[i-1][j]+=a[i][j+1];
            }
        }
    }

   for(i=0; i<15; i++){        // 一番上の行まで回す
        for(j=0; j<15; j++){     // 和の配列に代入する
            printf("%d,", a[i][j]);
        }
        printf("\n");
    }  

    printf("The answer is %d\n", a[0][0]);
}


// solved with hints, try again