#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n, m, len;
char s[100];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    gets(s);
    gets(s);
    //printf("s=%s__\n", s);
    len = strlen(s);
    cin >> m;
    //printf("m=%d\n", m);
    cout << n << " ";
    int k = 0;
    for (int i=0; i<m; i++) {
      int x;
      cin >> x;
      k = (k + x + len) % len;
      cout << s[k];
    }
    cout << endl;
  }
  return 0;
}
