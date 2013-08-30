#include <stdio.h>
#include <ctype.h>

#define s(n) scanf("%d", &n);
#define ss(n) scanf("%s", n);

int t,i;
char str[101], trans[26];
char ch;
int main() {
    s(t);
    ss(str);
    //printf("%s\n", str);
    for (i=0; i < 26;i++) {
        //printf("%c\n", str[i]);
        trans[i] = str[i] - ('a' + i);
        //printf("ban=%c, eng=%c, trans[%d] = %d\n", 'a' + i, str[i], i, trans[i]);
    }
    while(t--) {
        ss(str);
        i = 0;
        while(str[i] != '\0') {
            if (str[i] == '_') ch = ' ';
            else if (isalpha(str[i])) ch = str[i]+trans[tolower(str[i])-'a'];
            else ch = str[i];
            printf("%c", ch);
            i++;
        }
        printf("\n");
    }
    return 0;
}
