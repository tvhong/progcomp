#include <vector>

using namespace std;

class ZigZag {
  static const int N = 50;
  int dp[2][N];
  int longestZigZag(vector<int> numbers) {
    for (int i=0; i<numbers.size(); i++) {
      dp[0][i] = 1;
      dp[1][i] = 1;
      for (int j=0; j<i; j++) {
        if (numbers[i] > numbers[j])
          dp[0][i] = max(dp[0][i], dp[1][j] + 1);
        else
          dp[1][i] = max(dp[1][i], dp[0][j] + 1);
      }
    }
    return max(dp[1][numbers.size()-1], dp[0][numbers.size()-1]);
  }
};

int main() {
  return 0;
}
