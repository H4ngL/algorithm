import java.util.*;
import java.io.*;

class Solution {
	static int n, k;
	static int[][] dp;
	static int[] v;
	static int[] c;

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			dp = new int[n + 1][k + 1];
			v = new int[n + 1];
			c = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				st = new StringTokenizer(in.readLine());
				v[i] = Integer.parseInt(st.nextToken());
				c[i] = Integer.parseInt(st.nextToken());
			}

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= k; j++) {
					// 해당 위치에 물건을 넣을 수 없는 경우 
					if (v[i] > j)
						dp[i][j] = dp[i - 1][j];
					// 해당 위치에 물건을 넣을 수 있는 경우
					else
						dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - v[i]] + c[i]);
				}
			}

			sb.append("#").append(test_case).append(" ").append(dp[n][k]).append("\n");
		}

		System.out.println(sb);
	}
}