import java.util.*;
import java.io.*;

class Solution {
	static class Money {
		int value;
		int x;
		int y;

		Money(int value, int x, int y) {
			this.value = value;
			this.x = x;
			this.y = y;
		}
	}

	static int n, m, c;
	static int[][] honey;

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			honey = new int[n][n];
			List<Money> moneyList = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < n; j++) {
					honey[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= n - m; j++) {
					moneyList.add(new Money(cal(i, j), i, j));
				}
			}

			moneyList.sort((a, b) -> b.value - a.value);

			int ans = 0;
			for (int i = 0; i < moneyList.size(); i++) {
				Money first = moneyList.get(i);
				for (int j = i + 1; j < moneyList.size(); j++) {
					Money second = moneyList.get(j);
					if (!isOverlap(first, second)) {
						ans = Math.max(ans, first.value + second.value);
						break;
					}
				}
			}

			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}

		System.out.println(sb);
	}

	public static int cal(int x, int y) {
		int[] subarr = new int[m];
		for (int i = 0; i < m; i++) {
			subarr[i] = honey[x][y + i];
		}

		return getMaxMoney(subarr, 0, 0, 0);
	}

	public static int getMaxMoney(int[] subarr, int idx, int sum, int money) {
		if (sum > c)
			return 0;
		if (idx == subarr.length)
			return money;

		int exclude = getMaxMoney(subarr, idx + 1, sum, money);
		int include = getMaxMoney(subarr, idx + 1, sum + subarr[idx], money + subarr[idx] * subarr[idx]);

		return Math.max(exclude, include);
	}

	public static boolean isOverlap(Money a, Money b) {
		return (a.x == b.x && b.y < a.y + m);
	}

}