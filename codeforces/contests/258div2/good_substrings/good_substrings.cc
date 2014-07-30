#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e5 + 5;

long long odd[2], even[2];
long long tot_odds, tot_even;

int main() {
  char str[N];
  scanf("%s", str);
  for (int i=0; str[i]!='\0'; i++) {
    int id = str[i] - 'a';
    if (i & 1) {
      odd[id]++;
      tot_odds += odd[id];
      tot_even += even[id];
    } else {
      even[id]++;
      tot_even += odd[id];
      tot_odds += even[id];
    }
  }
  cout << tot_even << " " << tot_odds << endl;
  return 0;
}
