#include <bits/stdc++.h>

const int N = 8;

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        int i1 = -1, j1, i2, j2;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char ch;
                scanf("%c", &ch);
                if (ch == 'K') {
                    if (i1 == -1) {
                        i1 = i;
                        j1 = j;
                    } else {
                        i2 = i;
                        j2 = j;
                    }
                }
            }
            scanf("\n");
        }
        if ((abs(i1 - i2) % 4 == 0) && (abs(j1 - j2) % 4  == 0))
            printf("YES\n");
        else
            printf("NO\n");
        scanf("\n");
    }
    return 0;
}
