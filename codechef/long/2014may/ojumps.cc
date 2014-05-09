#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  n %= 6;
  printf("%s\n", (n == 0 || n == 1 || n==3) ? "yes" : "no");
  return 0;
}
