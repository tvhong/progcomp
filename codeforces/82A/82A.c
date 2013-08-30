/*
ID: Ray Hong
Date: 20120928
Task: double Cola

*/

#include <stdio.h>
#include <math.h>

int customer (int s);
int main() {
  const char *name[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  int s;
  scanf("%d", &s);
  s--;
  printf("%s\n", name[customer(s)]);
  return 0;
}

int customer (int s) {
  int reVal;
  int n;
  n = log(s/5.0+1) / log(2.0);
  reVal = (s-5*(pow(2, n)-1)) / pow(2, n);
  return reVal;
}
