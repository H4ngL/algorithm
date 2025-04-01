import java.util.*;
import java.io.*;

public class Main {
	static int n, m, ans;
	static int[][] map;
	static int[][] copyMap;

	static List<int[]> walls;
	static List<int[]> blank;
	static List<int[]> virus;

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		map = new int[n][m];
		walls = new ArrayList<>();
		blank = new ArrayList<>();
		virus = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());

				if (map[i][j] == 0)
					blank.add(new int[] { i, j });
				else if (map[i][j] == 2)
					virus.add(new int[] { i, j });
			}
		}

		comb(0, 0);
		System.out.println(ans);
	}

	public static void comb(int cnt, int start) {
		if (cnt == 3) {
			ans = Math.max(ans, calSafeArea());
			return;
		}

		for (int i = start; i < blank.size(); i++) {
			walls.add(blank.get(i));
			comb(cnt + 1, i + 1);
			walls.remove(walls.size() - 1);
		}
	}

	public static int calSafeArea() {
		copyMap();

		for (int[] v : virus) {
			bfs(v);
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copyMap[i][j] == 0)
					cnt++;
			}
		}

		return cnt;
	}

	public static void copyMap() {
		copyMap = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copyMap[i][j] = map[i][j];
			}
		}

		for (int[] wall : walls) {
			copyMap[wall[0]][wall[1]] = 1;
		}
	}

	public static void bfs(int[] start) {
		Deque<int[]> queue = new ArrayDeque<>();
		queue.add(start);

		while (!queue.isEmpty()) {
			int[] cur = queue.poll();

			for (int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;

				if (copyMap[nx][ny] == 0) {
					copyMap[nx][ny] = 2;
					queue.add(new int[] { nx, ny });
				}
			}
		}
	}

}
