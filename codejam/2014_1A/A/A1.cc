#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
const int N = 155;
const int L = 45;
int T, n, l;
ull outlets[N], devices[N];

void init() {
  memset(outlets, 0, sizeof outlets);
  memset(devices, 0, sizeof devices);
}

int count_1(ull n) {
  int cnt = 0;
  while (n) {
    if (n&1) cnt++;
    n >>= 1;
  }
  return cnt;
}

void solve() {
  map<ull, int> flips;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      ull tmp = devices[i] ^ outlets[j];
      flips[tmp]++; // because 1 flip can appear maximum once for every device[i]
    }
  }
  int min_1 = 50;
  typedef map<ull, int>::iterator it_type;
  for (it_type it = flips.begin(); it!=flips.end(); ++it) {
    if (it->second == n) {
      min_1 = min(min_1, count_1(it->first));
    }
  }
  if (min_1 == 50) {
    printf("NOT POSSIBLE\n");
  } else {
    printf("%d\n", min_1);
  }
}
int main() {
  scanf("%d", &T);
  char ch;
  for (int t = 1; t<=T; t++) {
    printf("Case #%d: ", t);
    scanf("%d %d", &n, &l);
    init();
    for (int i=0; i<n; i++) {
      for (int j=0; j<l; j++) {
        scanf(" %c", &ch);
        if (ch == '1') outlets[i] |= (1ULL<<j);
      }
    }
    for (int i=0; i<n; i++) {
      for (int j=0; j<l; j++) {
        scanf(" %c", &ch);
        //printf("ch=%c\n", ch);
        if (ch=='1') devices[i] |= (1ULL<<j);
      }
      //printf("devices[%d] = %x\n", i, devices[i]);
    }
    solve();
  }
  //printf("haha%llu\n", ((ull)1<<40));
  return 0;
}
