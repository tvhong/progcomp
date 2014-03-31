#include <cstdio>
#include <vector>

using namespace std;
class FlowerGarden {
public:
  vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {

    int n = height.size();
    vector<bool> used(n, 0);
    vector<int> res(n);
    //printf("%d\n", (int)used.size());

    for (int i=0; i<n; i++) {
      int maxH = 0;
      int pos = -1;
      for (int j=0; j<n; j++) {
        if (used[j]) continue;
        bool found = true;
        for (int k=0; k<n; k++) {
          if (j == k || used[k]) continue;
          if (!(wilt[k] < bloom[j] || wilt[j] < bloom[k]) &&
              height[j]>height[k])
            found = false;
        }
        if (found && height[j] > maxH) {
          maxH = height[j];
          pos = j;
        }
      }
      res[i] = maxH;
      used[pos] = 1;
    }
    return res;
  }
};

int main() {
  return 0;
}
