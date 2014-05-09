#include <cstdio>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

const int MAXL = 1005;
map<char, pair<int, int> > chmap;
void pre() {
  for (char ch = 'a'; ch <= 'r'; ch++) {
    int val = ch - 'a';
    chmap[ch] = make_pair(val/3 + 2, val%3 + 1);
  }
  chmap['s'] = make_pair(7, 4);
  chmap['t'] = make_pair(8, 1);
  chmap['u'] = make_pair(8, 2);
  chmap['v'] = make_pair(8, 3);
  chmap['w'] = make_pair(9, 1);
  chmap['x'] = make_pair(9, 2);
  chmap['y'] = make_pair(9, 3);
  chmap['z'] = make_pair(9, 4);
  chmap[' '] = make_pair(0, 1);
}

int main() {
  int T;
  pre();
  scanf("%d ", &T);
  /*
  for (char ch = 'a'; ch <='z'; ch++) {
    printf("%c %d %d\n",ch, chmap[ch].first, chmap[ch].second);
  }
  */
  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);
    char line[MAXL];
    gets(line);
    //printf("%s--", line);
    int len = strlen(line);
    for (int i=0; i<len; i++) {
      int x = chmap[line[i]].first;
      int m = chmap[line[i]].second;
      if (i > 0 && x == chmap[line[i-1]].first) printf(" ");
      for (int j=0; j<m; j++)
        printf("%d", x);
    }
    printf("\n");
  }
  return 0;
}
