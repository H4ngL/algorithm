import java.util.*;
import java.io.*;

public class Main {
	static int n, d, k, c;
	static int[] sushi;
	static int[] type;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());

		n = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		sushi = new int[n];
		type = new int[d + 1];
		for (int i = 0; i < n; i++) {
			sushi[i] = Integer.parseInt(in.readLine());
		}

		int ans = 0, cnt = 0, sum = 0;
		for (int i = 0; i < n + k - 1; i++) {
			int idx = i % n;

			if (type[sushi[idx]] == 0)
				sum++;
			type[sushi[idx]]++;
			cnt++;

			if (cnt == k) {
				int result = type[c] == 0 ? sum + 1 : sum;
				ans = Math.max(ans, result);

				type[sushi[i - k + 1]]--;
				if (type[sushi[i - k + 1]] == 0) {
					sum--;
				}
				cnt--;
			}
		}

		System.out.println(ans);
	}

}
