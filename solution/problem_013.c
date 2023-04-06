// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

int main(){
  char p[100][51];
  int ans[500];
  int q=0, q2=0, num=0, c=499, i, j;

  for(i=0; i<100; i++){     // 行目
    for(j=0; j<51; j++){    // 列目
      scanf("%c", &p[i][j]);
    }
  }

  for(int i=0; i<500; i++){ // ansを初期化する
    ans[i]=0;
  }

  for(i=0; i<100; i++){     // 計算をする
    for(j=49; j>=0; j--){ 
      char n;

      num=0;
      printf("ansは%d+",ans[c]);
      num+=ans[c];

      n=p[i][j];            // 入力
      printf("%d+",atoi(&n));
      num+=atoi(&n);

      printf("%d",q);
      // num+=q;
      q=0;

      printf("=%d,",num);

      if(num<10){           // 繰り上がらない場合
        ans[c]=num;
        printf("ans:%d\n",ans[c]);
        c--;
      }
      else{                 // 繰り上がる場合
        q=num/10;           // 繰り上がり分
        q2=num%10;          // １の位
        ans[c]=q2;
        printf("ans:%d,繰り上がりは%d\n",ans[c], q);
        ans[c-1]+=q;
        c--;
      }
    }
    printf("一行終わり\n");
    c=499;
  }

  printf("\n答えは");

  for(int i=0; i<500; i++){ 
    printf("%d", ans[i]);
  }
  
}