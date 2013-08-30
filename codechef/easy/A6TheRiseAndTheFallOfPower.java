package codechief.easy;

public class A6TheRiseAndTheFallOfPower {
	public static void main(String[] args) {
		A6TheRiseAndTheFallOfPower main = new A6TheRiseAndTheFallOfPower();
		main.run();
	}
	
	private void run() {
		String result = lastK(9999, 9999, 9);
		System.out.println(result);
	}
	
	private String lastK(long n, long m, int k) { //calculate n^m
		long mod = 1; 	// mask = 10^k
		for (int i = 1; i <= k; i++) {
			mod *= 10;
		}
//		System.out.println(mod);
		
		n = n % mod;
		long ans = 1;
		//do bit powering
		//5^25 = 5^5 * 5^20
		//5 ^ 0b101 = 5^0b1 * 5^0b100 
		long temp = n;	//temp is 5^0b1 or 5^0b10 or 5^0b100 etc.
		while (m != 0) {
			if ((m & 1) != 0) { // if the last bit is 1
				ans = (ans * temp) % mod;
			}
			temp = (temp * temp) % mod;
//			System.out.println(temp);
			m = m>>1;
		}
		
//		System.out.println(ans);
		StringBuilder result = new StringBuilder(String.valueOf(ans));
		while (result.length() < k) result.insert(0, '0');
		
		return result.toString();
	}

}
