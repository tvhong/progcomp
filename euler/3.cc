#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
vector<ll> p;

bool isPrime(ll n) {
  for (int i = 0; i < p.size(); ++i)
    if (n % p[i] == 0) return false;
  return true;
}

int main() {
  scanf("%lld", &n);
  p.push_back(2);
  while (n % 2 == 0) n /= 2;
  //for (int i = 3; n > 1 || i*i > n; i+=2) {
  for (int i = 3; n > 1; i+=2) {
    if (isPrime(i)) {
      p.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  ll res = (n == 1) ? p.back() : n;
  printf("%lld\n", res);
  return 0;
}
