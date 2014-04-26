#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAXL = 1005;
const int MAXW = 1005/2;
int main() {
  int T;
  scanf("%d ", &T);
  for (int t=1; t<=T; t++) {
    string line;
    vector<string> words;
    getline(cin, line);
    stringstream ss(line);
    string str;
    while (ss >> str) {
      words.push_back(str);
    }
    reverse(words.begin(), words.end());
    printf("Case #%d: ", t);
    for (int i=0; i<words.size(); i++) {
      if (i > 0) printf(" ");
      printf("%s", words[i].c_str());
    }
    printf("\n");
  }
  return 0;
}
