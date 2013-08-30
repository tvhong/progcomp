package codechief.easy;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class NICEQUAD {
	
	public static void main(String[] args) throws FileNotFoundException {
		int t, n, x, y;
		int type1 = 0;
		int type2 = 0;
		int type3 = 0;
		int type4 = 0;
		
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("in"));
		t = sc.nextInt();
		while (t > 0) {
			n = sc.nextInt();
			while (n > 0) {
				x = sc.nextInt();
				y = sc.nextInt();
				if (x > 0 && y > 0) type1++;
				else if (x > 0 && y < 0) type2++;
				else if (x < 0 && y < 0) type3++;
				else if (x < 0 && y > 0) type4++;
				n--;
			}
			System.out.println(type1 * type2 * type3 * type4);
			t--;
		}
		sc.close();
	}

}
