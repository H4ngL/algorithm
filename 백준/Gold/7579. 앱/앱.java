import java.io.*;
import java.util.*;

public class Main {
	static final int MAX = (int) 1e9;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[] memory = new int[n];
		int[] cost = new int[n];
		int totalMem = 0;
		int totalCost = 0;

		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < n; i++) {
			memory[i] = Integer.parseInt(st.nextToken());
			totalMem += memory[i];
		}

		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < n; i++) {
			cost[i] = Integer.parseInt(st.nextToken());
			totalCost += cost[i];
		}

		int[] dp = new int[totalMem + 1];
		Arrays.fill(dp, MAX);
		dp[0] = 0;

		for (int i = 0; i < n; i++) {
			for (int j = totalMem; j >= memory[i]; j--) {
				if (dp[j - memory[i]] + cost[i] < dp[j]) {
					dp[j] = dp[j - memory[i]] + cost[i];
				}
			}
		}

		int result = MAX;
		for (int i = m; i <= totalMem; i++) {
			result = Math.min(result, dp[i]);
		}

		System.out.println(result);
	}
}
