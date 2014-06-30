/* Solution to "Unequalled Consumption"
 *
 * The solution is by Lagrange interpolation and binary search.
 *
 * Complexity: O(n^2*(lcm(v_1,...,v_n) + q*v_1*log(P)))
 * (assuming BigInteger operations take constant time)
 *
 * (The solution uses BigInteger even though it doesn't have to)
 *
 * Author: Per Austrin
 *
 */

import java.math.BigInteger;
import java.util.Scanner;

public class consumption_pa {

    public static final long maxans = 100000000000000001L;

    int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
    int lcm(int a, int b) { return a / gcd(a,b) * b; }


    int n, mod, v[];
    long wtbl[][];

    long ways_brute(int c, int x) {
	if (x < 0) return 0;
	if (c == 0) return x % v[0] == 0 ? 1 : 0;
	if (wtbl[c-1][x] == -1)
	    wtbl[c-1][x] = ways_brute(c-1, x) + ways_brute(c, x-v[c]);
	return wtbl[c-1][x];
    }

    // lagrange interpolation for big weights
    BigInteger ways(long x) {
	long r = x % mod;
	long k = x / mod;
	BigInteger res = BigInteger.ZERO;
	if (k < n) return BigInteger.valueOf(ways_brute(n-1, (int)x));
	for (int i = 0; i < n; ++i) {
	    BigInteger num = BigInteger.valueOf(ways_brute(n-1, 
							   (int)(r + mod*i)));
	    BigInteger den = BigInteger.ONE;
	    for (int j = 0; j < n; ++j) {
		if (i != j) {
		    num = num.multiply(BigInteger.valueOf(k-j));
		    den = den.multiply(BigInteger.valueOf(i-j));
		}
	    }
	    res = res.add(num.divide(den));
	}
	return res;
    }

    Scanner sc;

    consumption_pa() {
	sc = new Scanner(System.in);
	int P = 0;
	while ((n = sc.nextInt()) > 0) {
	    System.out.println("Set " + ++P);
	    solve();
	}
	
    }
    
    public static void main(String args[]) {
	new consumption_pa();
    }

    void solve() {
	v = new int[n];
	wtbl = new long[n][];
	mod = 1;

	for (int i = 0; i < n; ++i) {
	    v[i] = sc.nextInt();
	    mod = lcm(mod, v[i]);
	}
	for (int i = 0; i < n; ++i) {
	    wtbl[i] = new long[mod*n];
	    for (int j = 0; j < mod*n; ++j)
		wtbl[i][j] = -1;
	}

	int q = sc.nextInt();

	while (q-- > 0) {
	    BigInteger P = sc.nextBigInteger();
	    long res = maxans;

	    // ways(n) is not increasing, hence we cannot apply a
	    // binary search straight off, but ways(n) is increasing
	    // for n with a fixed residue modulo any of the weights,
	    // so we do one binary search for each residue mod v[0].
	    for (int i = 0; i < v[0]; ++i) {
		long lo = -1, hi = 2;
		// first find a range for the binary search
		while ((lo+1) * v[0] + i < res && 
		       ways(hi * v[0] + i).compareTo(P) < 0) {
		    lo = hi;
		    hi = hi*2;
		}
		if ((lo+1) * v[0] + i >= res) continue;
		
		while (hi - lo > 1) {
		    long m = (lo + hi)/2;
		    BigInteger w = ways(m * v[0] + i);
		    if (w.compareTo(P) < 0) lo = m;
		    else hi = m;
		}
		// don't allow zero, we want positive answers.
		if (hi * v[0] + i == 0) ++hi;
		res = Math.min(res, hi * v[0] + i);
	    }
	    if (res == maxans) System.out.println("no candy for you");
	    else System.out.println(res);
	}
    }
}
