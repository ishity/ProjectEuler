// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

int main(){
  int c=0;
  long long int q=0, num=0, num2=0, k=1000000000, ans=0;
  char p[100][51], p2;

  for(int i=0; i<100; i++){     // 行目
    for(int j=0; j<51; j++){    // 列目&改行を含む
      scanf("%c", &p[i][j]);
    }
  }

  // 10桁以下の数値(num)を作る
  for(int i=0; i<100; i++){      // 行目
    for(int j=40; j<50; j++){    // 列目&改行を含む
      p2=p[i][j];
      num=atoi(&p2)*k;           // １桁(num1)ずつ求める
      num2+=num;                 // 10桁の数値(num2)を作る
      k/=10;
    }
    printf("%lld\n", num2);
    ans+=num2;
    k=1000000000;
    num=0;
    num2=0;
  }
  printf("The answer is %lld\n", ans);
}
