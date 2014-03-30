#include <cstdio>
#include <vector>

using namespace std;
class FlowerGarden {
private:
  vector<int> itoidx;

  bool bloom_comp(int i, int j) {
    return bloom[itoidx[i]] < bloom[itoidx[j]];
  }


public:
  vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {

    int n = height.size();
    vector<int> is_curr_flowers(n, 0);
    vector<int> curr_loc(n, -1);

    itoidx.reserve(n);
    for (int i=0; i<n; i++) 
      itoidx[i] = i;

    sort(itoidx.begin(), itoidx.end(), bloom_comp);
    int bloom_head = 0;
    for (int date = 1; date <= 365; date++) {
      if (bloom[bloom_head] != date)
        continue;

      for (int i=0; i<is_curr_flowers.size(); i++) {
        if (is_curr_flowers[i]) {
          if (wilt[i] < date) is_curr_flowers[i] = false;
        }
      }
      int iminh = -1;
      for (int i=0; i<n; i++) {
        if (is_curr_flowers[i]) 
          if (iminh == -1)
            iminh = i;
          else if (height[i] > height[iminh]);
      bloom_head++;
    }
  }
};

int main() {
  return 0;
}
