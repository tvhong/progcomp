#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>

#define x first
#define y second
#define mp make_pair
#define sz size()

using namespace std;

const int N = 1000;
const int Z = 26;

char a[5][5];
int f[Z];
void add (int j, char ch) {
  a[j/5][j%5] = ch + 'A' - 'a';
}

pair<int, int> getloc(char ch) {
  ch = ch - 'a' + 'A';
  for (int i=0; i<5; i++)
    for (int j=0; j<5; j++)
      if (a[i][j] == ch) return mp(i, j);
}

string line;
int main() {
  char str[N+5];
  while (gets(str) != NULL) {
    //str[strlen(str)-1] = '\0';
    line = string(str);
    for (int i=0; i<Z; i++) {
      f[i] = 0;
    }
    f['q'-'a'] = 1;
    int j = 0;
    for (int i =0; i<line.size(); i++) {
      if (line[i] < 'a' || line[i] > 'z') continue;
      if (!f[line[i]-'a']) {
        add(j, line[i]);
        f[line[i]-'a'] = 1;
        j++;
      }
    }
    char tmp = 'a';
    while (j<25) {
      while (f[tmp-'a']) tmp++;
      add(j++, tmp);
      f[tmp - 'a'] = 1;
    }
    /*
    for (int i =0; i<5; i++) {
      for (int j =0; j<5; j++)
        cout << a[i][j];
      cout << endl;
    }
    */
    gets(str);
    //str[strlen(str)-1] = '\0';
    string tmpline(str);
    line.clear();
    for (int i = 0; i < tmpline.sz; i++) {
      if (tmpline[i] < 'a' || tmpline[i] > 'z') continue;
      if (i > 0)
        if (tmpline[i] == line[line.size()-1] && (line.size()&1)) line.push_back('x');
      line.push_back(tmpline[i]);
    }
    if (line.size() & 1) line.push_back('x');
    //cout << line << endl;

    for (int i = 0; i<line.sz; i+=2) {
      if (i == line.sz-1) break;
      /*
      if (line[i] == line[i+1]) {
        char ch = line[i]+'A'-'a';
        cout <<ch << 'X';
        continue;
      }
      */
      pair<int, int> loc1 = getloc(line[i]);
      pair<int, int> loc2 = getloc(line[i+1]);
      if (loc1.x == loc2.x)
        cout << a[loc1.x][(loc1.y+1)%5] << a[loc2.x][(loc2.y+1)%5];
      else if (loc1.y == loc2.y)
        cout << a[(loc1.x+1)%5][loc1.y] << a[(loc2.x+1)%5][loc2.y];
      else
        cout << a[loc1.x][loc2.y] << a[loc2.x][loc1.y];
      //cout << endl << line[i] << line[i+1] << endl;
    }
    cout << endl;
  }
  return 0;
}
