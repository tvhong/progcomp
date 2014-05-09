#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair

using namespace std;

const int N = 155;
const int L = 45;
int T, n, l, ans;
string outlets[N], devices[N];

void flip(int j) {
  for (int i=0; i<n; i++) {
    outlets[i][j] ^= 1;
  }
}

void solve() {
  ans = 0;
  for (int j=0; j<l; j++) {
    int o0 = 0; //outlet
    int d0 = 0; //device
    for (int i=0; i<n; i++) {
      if (outlets[i][j] == 0) o0++;
      if (devices[i][j] == 0) d0++;
    }
    //printf("bit %d, o0 = %d, d0 = %d\n", j, o0, d0);
    if (o0 == d0) {
      continue;
    } else if (o0 == (n - d0)) {
      flip(j);
      ans++;
    } else {
      ans = -1;
      return;
    }
  }
  sort(devices, devices+n);
  sort(outlets, outlets+n);
  for (int i=0; i<n; i++) {
    if (devices[i] != outlets[i]) {
      /*
      printf("wrong at %d\n", i);
      for (int j=0; j<devices[i].size(); j++)
        printf("%d", devices[i][j]);
      printf(" ");
      for (int j=0; j<outlets[i].size(); j++)
        printf("%d", outlets[i][j]);
      printf("\n");
      */
      ans = -1;
      return;
    }
  }
}

int main() {
  scanf("%d", &T);
  char ch;
  for (int t = 1; t<=T; t++) {
    printf("Case #%d: ", t);
    scanf("%d %d", &n, &l);
    //printf("hahaha\n");
    for (int i=0; i<n; i++) {
      devices[i].clear();
      outlets[i].clear();
    }
    for (int i=0; i<n; i++) {
      for (int j=0; j<l; j++) {
        scanf(" %c", &ch);
        ch -= '0';
        outlets[i].push_back(ch);
        //printf("%d", ch);
      }
      //printf("\n");
    }
    for (int i=0; i<n; i++) {
      for (int j=0; j<l; j++) {
        scanf(" %c", &ch);
        ch -= '0';
        devices[i].push_back(ch);
        //printf("%d", ch);
      }
      //printf("\n");
    }
    solve();
    if (ans == -1) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
