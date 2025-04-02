import java.util.*;
import java.io.*;

class Solution {
	static class Place {
		int x, y, rank;

		Place(int x, int y, int rank) {
			this.x = x;
			this.y = y;
			this.rank = rank;
		}
	}

	static int n, m, r, c, l, ans;
	static int[][] map;
	static boolean[][] visited;

	// 상하좌우
	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			ans = 0;

			map = new int[n][m];
			visited = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < m; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			if (l != 1)
				bfs();
			sb.append("#").append(test_case).append(" ").append(ans == 0 ? 1 : ans).append("\n");
		}

		System.out.println(sb);
	}

	public static void bfs() {
		Deque<Place> queue = new ArrayDeque<>();
		queue.add(new Place(r, c, 1));
		visited[r][c] = true;
		ans++;

		while (!queue.isEmpty()) {
			Place p = queue.poll();

			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0 || visited[nx][ny])
					continue;

				if (isValid(map[p.x][p.y], map[nx][ny], i)) {
					visited[nx][ny] = true;
					ans++;
					if (p.rank + 1 < l)
						queue.add(new Place(nx, ny, p.rank + 1));
				}
			}
		}
	}

	public static boolean isValid(int t1, int t2, int dir) {
		int[][] directions = { {}, { 0, 1, 2, 3 }, { 0, 1 }, { 2, 3 }, { 0, 3 }, { 1, 3 }, { 1, 2 }, { 0, 2 } };

		int[] opposite = { 1, 0, 3, 2 };

		return contains(directions[t1], dir) && contains(directions[t2], opposite[dir]);
	}

	private static boolean contains(int[] arr, int key) {
		for (int val : arr) {
			if (val == key)
				return true;
		}
		return false;
	}

}