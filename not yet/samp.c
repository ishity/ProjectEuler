#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZEY 64   /* 行数 */
#define SIZEX 8    /* 1行あたりの文字数 */
int main() {
    char (*arr)[SIZEX];   // arrはchar[SIZEX]へのポインター
    int    y;
    char  tmp[8] = { 0 };
    // y*x分を確保、char[SIZEX]へのポインターなので、
    // SIZEY * char[SIZEX]分確保
    arr = malloc(sizeof(char) * SIZEY * SIZEX);
    for (y = 0; y < SIZEY; y++) {
        sprintf(tmp, "%02d", y + 1);
        strcpy(arr[y], tmp);
        printf("%s\n", arr[y]);  // 01 02 ... 64
    }
    free(arr);
    return 0;
}
