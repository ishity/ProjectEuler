// Find the product of the coefficients, and , for the quadratic expression that produces the maximum number of primes for consecutive values of , starting with 
//|a|も|b|も<1000で,n^2 + an + bでn=0~の時,連続して素数が生成されるかどうかを調べ,nが最大になるようなaとbを見つける
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool sosuu(int n){
    bool hantei = true;
    if(n==0 || n==1) hantei = false;
    else if(n==2) hantei = true;
    else{
        for(int i=2; i<n; i++){
            if(n%i==0){
                hantei = false;
                break;
            }else{
                hantei = true;
            }
        }
    }
    return hantei;
}

int quadratic(int a, int b){ // nの最大値を求める
    int n=0;
    while(sosuu(n*n+a*n+b) == true){ // 計算結果が素数の間
        n++;
    }
    return n-1;
}

int main(){
    int i, j, hantei=0, a=0, b=0, largest_n=-1;
    long long int produces=0;
    int amin=0, amax=10, bmin=39, bmax=42;
    // int amin=-999, amax=999, bmin=-1000, bmax=1000;
    // int amin=-80, amax=-74, bmin=1599, bmax=1604;

    // 素数かどうかの判定ー＞割れてしまうケース： n+a=b (bは素数) |a|<1000, |b|<=1000
    // b=42以下の素数の中で、a<10の時にn+a=bとなるnの最大値を求める

    for(i=bmin; i<=bmax; i++){ // bの値を決める
        if(sosuu(i) == true){ // iが素数の時
            for(j=amin; j<=amax; j++){ // aの値を決める
                // if(quadratic(a,b)>largest_n){ // formulaのnの最大値を更新
                //     largest_n = quadratic(a,b);
                //     a=j+1;
                //     b=i;
                // }
                printf("%d,",quadratic(a,b));
            }
        }
    }
    // produces = a*b;
    // printf("a:%d\n", a);
    // printf("b:%d\n", b);
    // printf("n:%d\n", largest_n);
    // printf("x:%lld\n", produces);
}

// 996004、-995006、995006