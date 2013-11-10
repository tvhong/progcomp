#include <cstdio>
#include <cstring>

#define SIZE 1010
using namespace std;

int main() {
    char str[SIZE][SIZE];
    int n, i, j;
    scanf("%d\n", &n);
    scanf("%s", &str[0]);
    //printf("%s\n", str[0]);

    int l = strlen(str[0]);
    //printf("%d\n", l);
    n %= l - 1;
    if (n != 0)
        n = (l - 1) - n;

    //printf("%d\n", n);

    for (j=1; j<=n; j++) {
        //string newstr;
        for (i=0; i<l; i+=2) {
            //newstr = str[j-1][i>>1];
            str[j][i] = str[j-1][i>>1];
            //cout << "ch=" << str[j-1][i>>1] << endl;
        }
        //cout << "ns" << newstr << endl;
        for (i=1; i<l; i+=2) {
            //newstr = str[j-1][l - 1 - i>>1];
            str[j][i] = str[j-1][l - 1 - (i>>1)];
            //printf("index=%d\n", l - 1 - (i>>1));
        }
        //cout << "j=" << j<<endl;
        //cout << "SHIT" << str[j] << "|" << newstr << endl;
    }
    /*
    for (i=0; i<=n; i++)
        printf("%s\n", str[i]);
    */
    printf("%s\n", str[n]);
    return 0;
}
