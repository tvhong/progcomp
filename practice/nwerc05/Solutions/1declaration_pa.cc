/* Solution to "Declaration of Content" from NWERC 05
 *
 * Author: Per Austrin
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct ing {
  string name;
  int lo, hi, rlo, rhi;
  ing(): hi(100), rlo(100), rhi(0) {
    getline(cin, name);
    istringstream in(name);
    if (in >> name >> lo) hi = lo;
    else lo = 1;
  }
};

typedef vector<ing> vi;
int poss[100][101][101], pid = 0;

bool Poss(int var, int val, int sum, vi &pr) {
  if (sum < 0 || var == pr.size()) return sum == 0;
  int &ans = poss[var][val][sum], i;
  if ((ans >> 16) != (var ? pid : ++pid))
    for (ans = pid<<16, i = pr[var].lo; i <= min(pr[var].hi, val); ++i)
      if (Poss(var+1, i, sum-i, pr)) ans |= 1, pr[var].rlo <?= i, pr[var].rhi >?= i;
  return ans & 0xFFFF;
}

int main(void) {
  memset(poss, 0, sizeof(poss));
  for (int P, n; cin >> P, P; ) {
    vi prods[10];
    string name[10], op, ingred;
    for (int i = 0, j; i < P && cin>>name[i]>>n; Poss(0, 100, 100, prods[i++]))
      for (j = 0, cin.get(); j < n; ++j) prods[i].push_back(ing());
    for (cin >> n; n-- && cin >> op >> ingred; cout << endl) {
      int minhi = 100, maxlo = 0, first = true, rlo, rhi;
      for (int j = 0; rlo = rhi = 0, j < P; ++j, minhi <?= rhi, maxlo >?= rlo)
	for (vi::iterator it = prods[j].begin(); it != prods[j].end(); ++it)
	  if (it->name == ingred) rhi = it->rhi, rlo = it->rlo;
      for (int j = 0; rlo = rhi = 0, j < P; ++j) {
	for (vi::iterator it = prods[j].begin(); it != prods[j].end(); ++it)
	  if (it->name == ingred) rhi = it->rhi, rlo = it->rlo;
	if (op == "least" && rlo <= minhi || op == "most" && rhi >= maxlo)
	  cout << (first ? "" : " ") << name[j], first = false;
      }
    }
  }
  return 0;
}
