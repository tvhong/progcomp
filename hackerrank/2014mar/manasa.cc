#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int E = 125;
int a[10];
int eight[E][10];
void pre() {
  //eight[0][0] = 1;
  for (int i = 0; i*8 < 1000; i++) {
    int j = i*8;
    int cnt = 0;
    while (j) {
      eight[i][j%10]++;
      j /= 10;
      cnt++;
    }
    while (cnt < 3) { cnt++; eight[i][0]++; }
  }
}

int main() {
  pre();
  int T;
  scanf("%d", &T);
  while (T--) {
    char str[N+5];
    scanf("%s", str);
    for (int i = 0; i < 10; i++) a[i] = 0;
    bool good = false;
    for (int i = 0; i < strlen(str); i++) {
      a[str[i] - '0']++;
    }
    int len = strlen(str);
    if (len < 3) {
      sort(str, str+len);
      do {
        int n;
        sscanf(str, "%d",&n);
        if (n % 8 == 0) good = true;
      } while (next_permutation(str, str+len));
    } else {
      for (int i = 0; i < E && !good; i++) {
        int j = 0;
        for (; j < 10; j++) {
          if (a[j] < eight[i][j]) break;
        }
        if (j == 10) {
          //cout << i << endl;
          good = true;
        }
      }
    }
    printf("%s\n", (good) ? "YES" : "NO");
  }
  return 0;
}
