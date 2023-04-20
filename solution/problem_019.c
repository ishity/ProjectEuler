// 1 Jan 1900 was a Monday.
// Thirty days has September, / April, June and November. / All the rest have thirty-one, / Saving February alone, / Which has twenty-eight, rain or shine. / And on leap years, twenty-nine. 
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZEY 366   /* 行数 */
#define SIZEX 102    /* 1行あたりの文字数 */

int main(){
    int year, j, i, mon=1, day=0, c=2, c2=0, ans=0, date[7]={1,2,3,4,5,6,7};
    int (*all)[SIZEX];   // arrはint[SIZEX]へのポインター
    all = malloc(sizeof(int) * SIZEY * SIZEX);    // SIZEY * int[SIZEX]分確保

    for(i=1; i<101; i++){
        year=1900+i;
        if(year%4==0 && (year%400)!=0){       // 閏年の時
            printf("閏年366日：%d\n", 1900+i);
            for(j=0; j<366; j++){
                if(c!=7){
                    all[i][j]=date[c];
                    c++;
                }else{
                    c=0;
                    all[i][j]=date[c];
                    c++;
                }

                if(j==day){
                    if(mon==4 || mon==6 || mon==9 || mon==11){
                        if(all[i][j]==1){
                            ans++;
                            mon++;
                            day+=30;
                        }else{
                            mon++;
                            day+=30;
                        }
                    }else if(mon==2){
                        if(all[i][j]==1){
                            ans++;
                            mon++;
                            day+=29;
                        }else{
                            mon++;
                            day+=29;
                        }
                    }else{
                        if(all[i][j]==1){
                            ans++;
                            mon++;
                            day+=31;
                        }else{
                            mon++;
                            day+=31;
                        }
                    }
                }
                printf("%d:%d,", j+1, all[i][j]);
            }
        }else{
            printf("not閏年365日：%d\n", 1900+i);
            for(j=0; j<366; j++){
                if(j==365){ 
                    all[i][j]=0;
                }else{
                    if(c!=7){
                        all[i][j]=date[c];
                        c++;
                    }else{
                        c=0;
                        all[i][j]=date[c];
                        c++;
                    }
                }

                if(j==day){
                    if(mon==4 || mon==6 || mon==9 || mon==11){
                        if(all[i][j]==1){
                            ans++;
                            mon++;
                            day+=30;
                        }else{
                            mon++;
                            day+=30;
                        }
                    }else if(mon==2){
                        if(all[i][j]==1){
                            ans++;
                            mon++;
                            day+=28;
                        }else{
                            mon++;
                            day+=28;
                        }
                    }else{
                        if(all[i][j]==1){
                            ans++;
                            mon++;
                            day+=31;
                        }else{
                            mon++;
                            day+=31;
                        }
                    }
                }
                printf("%d:%d,", j+1, all[i][j]);
            }
        }
        day=0;
        mon=1;
        printf("\n\n");
    }

    free(all);
    printf("The answer is %d\n", ans);
}


// --------------------------memo-----------------------------


// 閏年は366日！それ以外は365日！
// for(i=1; i<10; i++){
//     year=1900+i;
//     mon=1;
//     day=0;
//     for(j=0; j<366; j++){
//         if(year%4==0 && (year%400)!=0){       // 閏年の時
//             if(j==0 && all[i][j]==1) ans++;
//             else if(j==31 && all[i][j]==1) ans++;
//             else if(j==60 && all[i][j]==1) ans++;
//             else if(j==91 && all[i][j]==1) ans++;
//             else if(j==121 && all[i][j]==1) ans++;
//             else if(j==152 && all[i][j]==1) ans++;
//             else if(j==182 && all[i][j]==1) ans++;
//             else if(j==213 && all[i][j]==1) ans++;
//             else if(j==244 && all[i][j]==1) ans++;
//             else if(j==274 && all[i][j]==1) ans++;
//             else if(j==305 && all[i][j]==1) ans++;
//             else if(j==335 && all[i][j]==1) ans++;
//             else ans+=0;
//             printf("%d:%d,", j+1, all[i][j]);
//         }else{      // 閏年ではない時
//             if(j==0 && all[i][j]==1) ans++;
//             else if(j==31 && all[i][j]==1) ans++;
//             else if(j==59 && all[i][j]==1) ans++;
//             else if(j==90 && all[i][j]==1) ans++;
//             else if(j==120 && all[i][j]==1) ans++;
//             else if(j==151 && all[i][j]==1) ans++;
//             else if(j==181 && all[i][j]==1) ans++;
//             else if(j==212 && all[i][j]==1) ans++;
//             else if(j==243 && all[i][j]==1) ans++;
//             else if(j==273 && all[i][j]==1) ans++;
//             else if(j==304 && all[i][j]==1) ans++;
//             else if(j==334 && all[i][j]==1) ans++;
//             else ans+=0; 
//             printf("%d:%d,", j+1, all[i][j]);
//         }
//     }
//     printf("\n\n");
// }

// if(j==0 && all[i][j]==1) ans++;
// else if(j==31 && all[i][j]==1) ans++;
// else if(j==60 && all[i][j]==1) ans++;
// else if(j==91 && all[i][j]==1) ans++;
// else if(j==121 && all[i][j]==1) ans++;
// else if(j==152 && all[i][j]==1) ans++;
// else if(j==182 && all[i][j]==1) ans++;
// else if(j==213 && all[i][j]==1) ans++;
// else if(j==244 && all[i][j]==1) ans++;
// else if(j==274 && all[i][j]==1) ans++;
// else if(j==305 && all[i][j]==1) ans++;
// else if(j==335 && all[i][j]==1) ans++;
// else ans+=0;