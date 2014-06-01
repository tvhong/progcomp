#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int MAXL = 105;
int T, n;
int m[N];
pair<char, int> a[N][N];
void init() {
  memset(m, 0, sizeof m);
}

void solve() {
  bool good = true;
  /*
  for (int i=0; i<n; i++) 
    printf("m[%d] = %d\n", i, m[i]);
    */
  for (int i=0; i<n-1 && good; i++)
    if (m[i] != m[i+1]) {
      good = false;
    } else {
      for (int k=0; k<m[i]; k++) {
        if (a[i][k].first != a[i+1][k].first) {
          good = false;
        }
      }
    }
  if (!good) {  
    printf("Fegla Won\n");
    return;
  }
  int ans = 0;
  for (int k=0; k<m[0]; k++) {
    int sum = 0;
    for (int i=0; i<n; i++) {
      sum += a[i][k].second;
    }
    double avg = sum/n;
    int avgi = (int)avg;
    if (avg - (int)avg > 0.5)
      avgi = avgi+1;
    //printf("k = %d sum=%d avg = %d\n", k, sum, avgi);
    for (int i=0; i<n; i++) {
      ans += abs(a[i][k].second - avgi);
    }
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t<=T; t++) {
    init();
    printf("Case #%d: ", t);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
      char s[MAXL];
      scanf("%s", s);
      char prev = s[0];
      int cnt = 1;
      int j;
      int len = strlen(s);
      for (j= 1; j<len; j++) {
        if (s[j] != s[j-1]) {
          a[i][m[i]++] = make_pair(s[j-1], cnt);
          prev = s[j];
          cnt = 1;
          //printf("added %c %d\n", a[m-1].first, a[m-1].second);
        } else {
          cnt++;
        }
      }
      a[i][m[i]++] = make_pair(s[len-1], cnt);
      //printf("added %c %d\n", a[m-1].first, a[m-1].second);
    }
    solve();
  }
  return 0;
}
