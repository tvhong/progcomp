#include <bits/stdc++.h>

using namespace std;
bool isPalindrome(int n) {
  string s;
  int len = 0;
  while (n) {
    s[len++] = n % 10;
    n /= 10;
  }
 
  for (int i=0; i<len/2; i++) {
    if (s[i] != s[len-1-i]) return false;
  }
  return true;
}
int main() {
  int res = 0;
  for (int i=999; i>=100; i--)
    for (int j=999; j>=i; j--) {
      if (i*j < res) break;
      if (isPalindrome(i*j)) {res = max(res, i*j);}
    }
hell:
  printf("%d\n", res);
  return 0;
}
