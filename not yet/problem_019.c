// 1 Jan 1900 was a Monday.
// Thirty days has September, / April, June and November. / All the rest have thirty-one, / Saving February alone, / Which has twenty-eight, rain or shine. / And on leap years, twenty-nine. 
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZEY 365   /* 行数 */
#define SIZEX 2    /* 1行あたりの文字数 */

int main(){
    int sun=0, mon=0, year=1900, j, i, c=1, c2=1;
    char day[7][3]={"su", "mo", "tu", "we", "th", "fr", "sa"};
    // char days[365][2];

    char (*days)[SIZEX];   // arrはchar[SIZEX]へのポインター
    // // y*x分を確保、char[SIZEX]へのポインターなので、
    // // SIZEY * char[SIZEX]分確保
    days = malloc(sizeof(char) * SIZEY * SIZEX);
    printf("あ\n");
    strcpy(days[0], day[0]);
    printf("%s,", days[0]);

    printf("あ\n");
    while(c<365){
        // 1900年の1月〜12月の間、日曜は何回来るののか数える
        for(i=1; i<13; i++){
            if(i==4 || i==6 || i==9 || i==11){  // 30日の月
                for(j=0; j<31; i++){
                    strcpy(days[c], day[c2]);
                    c++;
                    c2++;
                }
            }else if(year%4==0){      // 2月                        
                if(year%400==0){      // 閏年ではない
                    for(j=0; j<28; i++){
                        strcpy(days[c], day[c2]);
                        // printf("%s,", days[c]);
                        c++;
                        c2++;
                    }
                }else{                 // 閏年である
                    for(j=0; j<29; i++){
                        strcpy(days[c], day[c2]);
                        c++;
                        c2++;
                    }
                }
            }else{                    // 31日の月
                for(j=0; j<30; i++){
                    strcpy(days[c], day[c2]);
                    c++;
                    c2++;
                }
            }
            if(c2==7)c2=0;
        }
    }
    printf("ああ\n");
    for(i=0; i<365; i++){
        printf("%s,", days[i]);
    }
    free(days);
}
