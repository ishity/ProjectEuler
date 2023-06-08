// For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
// What is the total of all the name scores in the file?
// gcc problem_022.c -o problem_022 | ./problem_022  |   p022_names.txt     

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 配列の長さを返す
int arrayLength (char* array[]) {
    int size  = 0;
    for(int i=0; i<50000; i++){
        if(array[i] != NULL){
            size++;
        }
    }
    return size;
}

// アルファベットの数字を求める
int alphabetNum (char *m, char *str) {
    int aNum=0, sum=0;
    while(*str != '\0'){ 
        for(int j=0; j<26; j++){
            if(*str==m[j]){
                printf("%c:%d ", *str, j+1);
                aNum = j+1;
            }
        }
        str++;
        sum += aNum;
    }
    return sum;
}

// intを受け取ったら、それを配列に分解して返す
int* separateToArray (int num){
    int i;
    int *array = (int *)malloc(50 * sizeof(int));
    for(int i=0; i<50; i++){
        array[i]=0;
    }
    for(i=29; i>=0; i--){
        // 1の位を配列に格納
        array[i] = num%10;
        num /= 10;
    }
    return array;
}

int main(){
    FILE * fp = NULL;
    char buf[50000], *name[50000], *str, *name2[50000],m[26], moji;
    int i, j, c=0, sum[30], k[10], l=1, n, nameNum, *a;

    // アルファベットを配列に格納
    i=0;
    for(moji='A'; moji<='Z'; moji++){
        m[i]=moji;
        i++;
    }

    // 初期化
    for(i=0; i<30; i++){
        sum[i]=0;
        k[i]=0;
    }

    //	memo.txtファイルを書き込み可能でオープン
	fp = fopen("p022_names.txt", "r");
    if(fp==NULL){
        printf("file cannot be opened\n");
    }

    fgets(buf, 50000, fp);      // bufに一行を読み込む
    name[0] = strtok(buf, "\",\""); // strtokで","ごとに分解してnameに格納
    i=0;
    while(name[i]!=NULL){
        i++;
        name[i] = strtok(NULL, "\",\""); 
    }

    // ***** nameをアルファベット順にソートする *****
    i=0;
    while(name[i]!=NULL){
        if(i==0){ // name2に追加
            name2[0] = name[i];
        }else{    // nameに追加
            for(j=arrayLength(name2)-1; j>=0; j--){ // name2
                if(strcmp(name[i], name2[j]) < 0){ // 配列の最後から見る
                    str = name[i];
                    name2[j+1] = name2[j];
                    name2[j] = str;
                } else {
                    name2[j+1] = name[i];
                    break;
                }
            }
        }
        i++;
    }

    // ***** アルファベットの値を計算する *****
    long long int answer=0;
    for(i=0; i<5163; i++){
    // for(i=0; i<10; i++){
        printf("%d-", i);
        n = alphabetNum(m, name2[i]); // アルファベットの和
        nameNum = (i+1)*n;
        printf("%d -> %d*%d=%d ",n,i+1,n,nameNum);
        answer += nameNum;


        // You don't need to separateToArray........

        // a = separateToArray(nameNum); 
        // for(j=29; j>=0; j--){
        //     int sumTwo = sum[j]+a[j];
        //     if(sumTwo>10){
        //         sum[j] = sumTwo%10;
        //         k[j-1] += sumTwo/10;
        //     }else{
        //         sum[j] = sumTwo;
        //     }
        //     a[j] = 0;
        // }

        // for(j=29; j>=0; j--){      // 繰り上がりの処理
        //     int sumK = sum[j]+k[j];
        //     if(sumK<10){
        //         sum[j]=sumK; 
        //         k[j]=0;
        //     }else{
        //         sum[j]=sumK%10; 
        //         k[j]=0; 
        //         k[j+1]+=sumK/10;
        //     }
        // }

        // for(j=1; j<31; j++){
        //     printf("%d", sum[j-1]);
        // }


        printf("\n");
    }
    printf("\n\nThe answer is ");
    
    // for(j=1; j<31; j++){
    //     printf("%d", sum[j-1]);
    // }

    printf("%lld\n", answer);
    fclose(fp);
}

