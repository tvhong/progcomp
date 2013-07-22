#include <iostream>
using namespace std;

const int MOD = 1000000007;

int fastPow(int a, int n) {
	int p = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			p = (long long) p * a % MOD;
		}
		a = (long long) a * a % MOD;
		n /= 2;
	}
	return p;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		// (-1)^n = n % 2 ? -1 : 1
		int ans = fastPow(3, n) + 3 * (n % 2 ? -1 : 1);

		// It is really sad that I wrote solution in this form
		// only in two days before the end of the contest.
		// Our test data do not catch the abscence of the next if.
		// There are only three values of N < 1e9
		// for which this if is really needed: 316884446, 500000003, 816884449
		if (ans < 0) {
			ans += MOD;
		}

		// On the other hand, it very surprising but the next if
		// is not needed at all in this problem, since all three
		// congruences 3^n = MOD-1 (mod MOD), 3^n = MOD-2 (mod MOD)
		// and 3^n = MOD-3 (mod MOD) have no solutions for MOD = 10^9 + 7
		if (ans >= MOD) {
			ans -= MOD;
		}

		cout << ans << endl;
	}
	return 0;
}
