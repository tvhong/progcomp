import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static final int SIZE = 350;

	static BigInteger choose(int n, int k) {
		if (k == 0) return BigInteger.ONE;
		return choose(n-1, k-1).multiply(BigInteger.valueOf(n)).divide(BigInteger.valueOf(k));
	}
	
	public static void main(String[] argv) {
		Scanner sc = new Scanner(System.in);
		int[] a = new int[SIZE];
		int t = sc.nextInt();
		while (t-- != 0) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			BigInteger m = sc.nextBigInteger();
			if (m.compareTo(choose(n, k)) > 0) {
				System.out.println("-1");
				continue;
			}
			int nn = n;
			for (int i=0; i < n; i++) {
				if (nn <= k) {
					a[i] = 1;
				} else if (choose(nn-1, k).compareTo(m) < 0) {
					m = m.subtract(choose(nn-1, k));
					a[i] = 1;
					k--;
				} else {
					a[i] = 0;
				}
				nn--;
				//System.out.println(nn+","+k+","+m);
			}
			for (int i=0; i<n ;i++)
				System.out.print(a[i]);
			System.out.println();
		}
		sc.close();
	}
}