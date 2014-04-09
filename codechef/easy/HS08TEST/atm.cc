#include <iostream>
#include <cstdio>

using namespace std;

int w;
double balance;

int main() {
  cin >> w >> balance;
  printf("%.2f\n", (w%5==0 && balance-w-0.5 >= 0) ? balance - w - 0.5 : balance);
  return 0;
}
