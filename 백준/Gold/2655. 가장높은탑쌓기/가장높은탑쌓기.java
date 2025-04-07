import java.util.*;
import java.io.*;

public class Main {
	static class Brick {
		int id, width, height, weight;

		Brick(int id, int width, int height, int weight) {
			this.id = id;
			this.width = width;
			this.height = height;
			this.weight = weight;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());

		Brick[] bricks = new Brick[n + 1];
		int[] dp = new int[n + 1]; // dp[i] : i번째 벽돌을 맨 위에 둘 때 최대 높이
		int[] path = new int[n + 1];

		bricks[0] = new Brick(0, 0, 0, 0);
		for (int i = 1; i <= n; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int width = Integer.parseInt(st.nextToken());
			int height = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			bricks[i] = new Brick(i, width, height, weight);
		}

		// 내림차순 정렬
		Arrays.sort(bricks, 1, n + 1, (a, b) -> b.width - a.width);

		int maxHeight = 0;
		int maxIndex = 0;

		for (int i = 1; i <= n; i++) {
			dp[i] = bricks[i].height;
			for (int j = 1; j < i; j++) {
				if (bricks[j].weight > bricks[i].weight) {
					if (dp[i] < dp[j] + bricks[i].height) {
						dp[i] = dp[j] + bricks[i].height;
						path[i] = j; // i번 벽돌 아래에는 j번 벽돌
					}
				}
			}

			if (maxHeight < dp[i]) {
				maxHeight = dp[i];
				maxIndex = i;
			}
		}

		Deque<Integer> q = new ArrayDeque<>();
		while (maxIndex != 0) {
			q.add(bricks[maxIndex].id);
			maxIndex = path[maxIndex];
		}

		System.out.println(q.size());
		while (!q.isEmpty()) {
			System.out.println(q.pop());
		}
	}
}
