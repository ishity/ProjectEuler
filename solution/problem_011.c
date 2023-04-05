// The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
// What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int n[20][20], c=0;
    long long int ans1=1, ans2=0;
    for(int i=0; i<20; i++){            // 行目
        for(int j=0; j<20; j++){        // 列目
            scanf("%d%*c", &n[i][j]);
        }
    }

    // up&down
    for(int i=0; i<17; i++){
        for(int j=0; j<20; j++){
            for(int k=0; k<4; k++){
                // printf("%d,", n[i+k][j]);
                ans1*=n[i+k][j];
            }
            // printf("ans1 is %lld\n", ans1);
            if(ans1>ans2) ans2=ans1;
            ans1=1;
        }
    }

    // left&right
    for(int i=0; i<20; i++){
        for(int j=0; j<17; j++){
            for(int k=0; k<4; k++){
                // printf("%d,", n[i][j+k]);
                ans1*=n[i][j+k];
            }
            // printf("ans1 is %lld\n", ans1);
            if(ans1>ans2) ans2=ans1;
            ans1=1;
        }
    }

    // diagonally right
    for(int i=0; i<17; i++){        // 行目
        for(int j=0; j<17; j++){     // 列目
            for(int k=0; k<4; k++){
                // printf("%d,", n[i+k][j+k]);
                ans1*=n[i+k][j+k];
            }
            // printf("ans1 is %lld\n", ans1);
            if(ans1>ans2) ans2=ans1;
            ans1=1;
        }
    }
    
    // diagonally left
    for(int i=0; i<17; i++){        // 行目
        for(int j=3; j<20; j++){     // 列目
            for(int k=0; k<4; k++){
                // printf("%d,", n[i+k][j-k]);
                ans1*=n[i+k][j-k];
            }
            // printf("ans1 is %lld\n", ans1);
            if(ans1>ans2) ans2=ans1;
            ans1=1;
        }
    }

    printf("The answer is %lld\n", ans2);
}
