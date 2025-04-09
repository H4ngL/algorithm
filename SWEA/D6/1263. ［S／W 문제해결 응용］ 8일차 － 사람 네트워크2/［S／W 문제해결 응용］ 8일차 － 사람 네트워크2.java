import java.util.*;
import java.io.*;

class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int n = Integer.parseInt(st.nextToken());

			int[][] dist = new int[n][n];
			for (int i = 0; i < n; i++)
				Arrays.fill(dist[i], (int) 1e9);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int num = Integer.parseInt(st.nextToken());
					if(i == j) dist[i][j] = 0;
					else if (num == 1)
						dist[i][j] = 1;
				}
			}

			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						dist[i][j] = Math.min(dist[i][k] + dist[k][j], dist[i][j]);
					}
				}
			}

			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				int sum = 0;
				for (int j = 0; j < n; j++) {
					sum += dist[i][j];
				}
				ans = Math.min(ans, sum);
			}

			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}

		System.out.println(sb);
	}
}