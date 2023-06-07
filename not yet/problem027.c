// Find the product of the coefficients, and , for the quadratic expression that maxAB the maximum number of primes for consecutive values of , starting with 
//|a|も|b|も<1000で,n^2 + an + bでn=0~の時,連続して素数が生成されるかどうかを調べ,nが最大になるようなaとbを見つける
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool sosuu(int num){ //素数かどうかの判定
    bool hantei = true;
    int n = abs(num);

    if(n==0 || n==1) return false;
    else if(n==2)return true;
    else{
        for(int i=2; i<n; i++){
            if(n%i==0){
                hantei = false;
                break;
            }else{
                hantei = true;
            }
        }
        return hantei;
    }
}

int quadratic(int a, int b){ // 連続して素数になるnの最大値を求める
    int n=0, num=0;
    
    while(true){ // 計算結果が素数の間
        if(sosuu(n*n+a*n+b) == true){
            n++;
        }else{
            break;
        }
    }
    return n-1;
}

int main(){
    int b, a, hantei=0, maxN=-1, c, ansA, ansB;
    long long int maxAB=0;
    // int amin=0, amax=10, bmin=39, bmax=42;
    int amin=-999, amax=999, bmin=-1000, bmax=1000;
    // int amin=-80, amax=-74, bmin=1599, bmax=1604;
    // int amin=-80, amax=80, bmin=-1604, bmax=1604;

    // 素数かどうかの判定ー＞割れてしまうケース： n+a=b (bは素数) |a|<1000, |b|<=1000
    // b=42以下の素数の中で、a<10の時にn+a=bとなるnの最大値を求める

    for(b=bmin; b<=bmax; b++){         // bの値を決める
        if(sosuu(b) == true){          // b=bが素数の時
            for(a=amin; a<=amax; a++){ // aの値を決める
                c = quadratic(a,b);    // nの最大値を求める
                if(c>maxN){            // formulaのnの最大値を更新
                    printf("更新%d->%d\n",maxN, c);
                    maxN = c;
                    maxAB = a*b;
                    ansA = a;
                    ansB = b;
                }
            }
        }
    }
    printf("a:%d\n", ansA);
    printf("b:%d\n", ansB);
    printf("n:%d\n", maxN);
    printf("x:%lld\n", maxAB);
}

// 996004、-995006、995006、-60878、60878、-60939、