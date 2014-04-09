package codechief.easy;

import java.util.Scanner;

public class VoteForTheNoodleSoup {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			int n = sc.nextInt();
			if (n == 0) break;
			long users = 0;
			for (int i = 0; i < n; i++) {
				String poVote = sc.next();
				int score = sc.nextInt();
				
				if (poVote.equals("P")) score--;
				else score++;
				score = Math.abs(score);
				
				if (score > users) users = score;
				else if ((score & 1) != (users & 1)) users++;
			}
			System.out.println(users);
		}
		sc.close();
	}
}
