#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll N = 10001;
vector<ll> p;
int i;
bool isPrime(ll num) {
  for (int j=0; j<p.size(); ++j) {
    if (p[j]*p[j] > num) return true;
    if (num % p[j] == 0) return false;
  }
  return true;
}

bool isPrime2(ll num) {
  if (num == 1) return false;
  if (num < 4) return true;
  if (num % 2 == 0) return false;
  if (num % 3 == 0) return false;
  ll sqrt_num = floor(sqrt(num));
  ll f = 6;
  while (f <= sqrt_num) {
    if (num % (f-1) == 0) return false;
    if (num % (f+1) == 0) return false;
    f+=6;
  }
  return true;
}
  

int main() {
  p.push_back(2);
  ll num = 3;
  ll cnt = 1;
  while (cnt < N) {
    if (isPrime(num)) {
      p.push_back(num);
      cnt++;
    }
    num+=2;
  }
  for (int k=0; k<5; k++)
    printf("%lld ", p[k]);
  printf("\n");
  printf("%lld\n", p.back());
  return 0;
}
