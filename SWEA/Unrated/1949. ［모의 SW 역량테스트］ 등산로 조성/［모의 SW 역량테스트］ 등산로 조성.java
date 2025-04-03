import java.util.*;
import java.io.*;

class Solution {
	static class Info {
		int x, y, height;

		Info(int x, int y, int height) {
			this.x = x;
			this.y = y;
			this.height = height;
		}
	}

	static int n, k, ans;
	static int[][] map;
	static int[][] length;

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			map = new int[n][n];
			int maxHeight = 0;

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					maxHeight = Math.max(maxHeight, map[i][j]);
				}
			}

			ans = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int cut = 0; cut <= k; cut++) {
						map[i][j] -= cut;
						updateLength(maxHeight);
						updateAns();
						map[i][j] += cut;
					}
				}
			}

			sb.append("#").append(test_case).append(" ").append(ans).append("\n");
		}

		System.out.println(sb);
	}

	public static void updateLength(int maxHeight) {
		length = new int[n][n];
		Deque<Info> q = new ArrayDeque<>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maxHeight) {
					q.add(new Info(i, j, map[i][j]));
					length[i][j] = 1;
				}
			}
		}


		while (!q.isEmpty()) {
			Info cur = q.poll();

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (map[nx][ny] < cur.height) {
					if (length[nx][ny] < length[cur.x][cur.y] + 1) {
						length[nx][ny] = length[cur.x][cur.y] + 1;
						q.add(new Info(nx, ny, map[nx][ny]));
					}
				}
			}
		}
	}

	public static void updateAns() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = Math.max(ans, length[i][j]);
			}
		}
	}
}
