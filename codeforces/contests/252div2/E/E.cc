#include <cstdio>
#include <iostream>

using namespace std;

int x, k, p;
int f(int x) {
  int res = 0;
  while (x && !(x&1)) {
    res++;
    x >>= 1;
  }
  return res;
}

int main() {
  scanf("%d %d %d", &x, &k, &p);
  double ans = 0;
  double psucc = p*1.0 / 100;
  double pfail = (100.0 - p)/100;
  printf("psucc=%f, pfail=%f\n", psucc, pfail);
  for (int i=0; i<=k; i++) {
    //i is the number of fails
    double prob = 1.0;
    for (int j=1; j<=k; j++) {
      if (j <= i) prob *= pfail; //fail
      else prob *= psucc; //success
    }
    ans += prob * ((k-i) + f(x+i));
  }
  printf("%f\n", ans);
  //cout << ans;
  return 0;
}
