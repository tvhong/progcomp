#include <stdio.h>
#include <ctype.h>

int i,j,t,r,c,k;
char a[100][101];
int noSpoon;
char ch;

int isSpoon(int i, int j) {
    if ((i+4 < r) &&
            (a[i][j] == 's' || a[i][j] == 'S') &&
            (a[i+1][j] == 'p'|| a[i+1][j] == 'P') && 
            (a[i+2][j] == 'o'|| a[i+2][j] == 'O') &&
            (a[i+3][j] == 'o'|| a[i+3][j] == 'O') &&
            (a[i+4][j] == 'n'|| a[i+4][j] == 'N'))
        return 1;

    if ((j+4 < c) &&
            (a[i][j] == 's' || a[i][j] == 'S') &&
            (a[i][j+1] == 'p'|| a[i][j+1] == 'P') && 
            (a[i][j+2] == 'o'|| a[i][j+2] == 'O') &&
            (a[i][j+3] == 'o'|| a[i][j+3] == 'O') &&
            (a[i][j+4] == 'n'|| a[i][j+4] == 'N'))
        return 1;
    return 0;
}

int main() {
    for (scanf("%d", &t); t--; ) {
        scanf("%d %d", &r, &c);
        //gets(a[0]);
        for (i = 0; i < r; i++) {
            //gets(a[i]);
            scanf("%s", a[i]);
            //printf("%sEND\n", a[i]);
        }
        noSpoon = 1;
        for (i = 0; i < r && noSpoon; i++) {
            for (j = 0; j < c && noSpoon; j++) {
                if ((i+4 < r) &&
                        (a[i][j] == 's' || a[i][j] == 'S') &&
                        (a[i+1][j] == 'p'|| a[i+1][j] == 'P') && 
                        (a[i+2][j] == 'o'|| a[i+2][j] == 'O') &&
                        (a[i+3][j] == 'o'|| a[i+3][j] == 'O') &&
                        (a[i+4][j] == 'n'|| a[i+4][j] == 'N'))
                    noSpoon = 0;

                if ((j+4 < c) &&
                        (a[i][j] == 's' || a[i][j] == 'S') &&
                        (a[i][j+1] == 'p'|| a[i][j+1] == 'P') && 
                        (a[i][j+2] == 'o'|| a[i][j+2] == 'O') &&
                        (a[i][j+3] == 'o'|| a[i][j+3] == 'O') &&
                        (a[i][j+4] == 'n'|| a[i][j+4] == 'N'))
                    noSpoon = 0;
            }
        }
        if (noSpoon) printf("There is indeed no spoon!\n");
        else printf("There is a spoon!\n");
    }
    return 0;
}
