#include <stdio.h>
#include <string.h>

int main() {
    int n, i, bad;
    int count[10];
    int pin[6];
    scanf("%d", &n);
    while (n--) {
        scanf("\n");
        memset(count, 0, sizeof(count));
        for (i=0; i<6; i++) {
            int ch = getchar();
            ch -= '0';
            pin[i] = ch;
            count[ch]++;
        }
        bad =0;
        for (i=0; i<10; i++)
            if (count[i] > 2)
                bad = 1;
        for (i=0; i<4 && !bad; i++)
            if (
                 (pin[i] == pin[i+1]-1 && pin[i+1] == pin[i+2]-1) ||
                 (pin[i] == pin[i+1]+1 && pin[i+1] == pin[i+2]+1)
               )
                bad = 1;
        printf(bad ? "WEAK\n" : "ACCEPTABLE\n");
    }
    return 0;
}
