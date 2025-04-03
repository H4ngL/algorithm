import java.util.*;
import java.io.*;

class Solution {
	static int n, l, score;
	static int[] taste;
	static int[] calorie;
	static int[][] dp;

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T;
		T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());

			taste = new int[n];
			calorie = new int[n];
			dp = new int[n + 1][l + 1];

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				taste[i] = Integer.parseInt(st.nextToken());
				calorie[i] = Integer.parseInt(st.nextToken());
			}

			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= l; j++) {
					if (calorie[i - 1] > j) {
						dp[i][j] = dp[i - 1][j];
					} else {
						dp[i][j] = Math.max(dp[i - 1][j], taste[i - 1] + dp[i - 1][j - calorie[i - 1]]);
					}
				}
			}

			sb.append("#" + test_case + " " + dp[n][l] + "\n");
		}

		System.out.println(sb);
	}
}