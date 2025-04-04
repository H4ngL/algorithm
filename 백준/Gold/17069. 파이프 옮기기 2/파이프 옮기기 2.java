import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[][] house;
	static long[][][] dp;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());

		house = new int[n][n];
		dp = new long[n][n][3]; // 가로, 세로, 대각선
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < n; j++) {
				house[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dp[0][1][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 2; j < n; j++) {
				if (house[i][j] == 1)
					continue;

				// 가로 방향
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

				// 세로 방향
				if (i > 0)
					dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

				// 대각선 방향
				if (i > 0 && house[i - 1][j] == 0 && house[i][j - 1] == 0)
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}

		System.out.println(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2]);
	}

}
