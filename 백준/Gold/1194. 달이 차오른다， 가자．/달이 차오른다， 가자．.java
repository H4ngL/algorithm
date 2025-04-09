import java.util.*;
import java.io.*;

public class Main {
	static int n, m;
	static char[][] maze;
	static boolean[][][] visited;

	static int[] dy = { -1, 1, 0, 0 };
	static int[] dx = { 0, 0, -1, 1 };

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		maze = new char[n][m];
		visited = new boolean[n][m][64];

		int[] start = new int[2];
		for (int i = 0; i < n; i++) {
			String str = in.readLine();
			for (int j = 0; j < m; j++) {
				maze[i][j] = str.charAt(j);
				if (maze[i][j] == '0') {
					start[0] = i; start[1] = j;
					maze[i][j] = '.';
				}
			}
		}

		int ret = bfs(start);
		System.out.println(ret);
	}

	public static int bfs(int[] start) {
		Deque<int[]> q = new ArrayDeque<>();
		q.add(new int[] { start[0], start[1], 0, 0 }); // y좌표, x좌표, 이동 횟수, key
		visited[start[0]][start[1]][0] = true;

		while (!q.isEmpty()) {
			int[] cur = q.poll();
			int ck = cur[3];

			for (int i = 0; i < 4; i++) {
				int ny = cur[0] + dy[i];
				int nx = cur[1] + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m || maze[ny][nx] == '#')
					continue;

				if (maze[ny][nx] == '1')
					return cur[2] + 1;

				if (maze[ny][nx] == '.' || isValid(maze[ny][nx], ck)) {
					int nk = getKey(maze[ny][nx], ck);

					if (!visited[ny][nx][nk]) {
						q.add(new int[] { ny, nx, cur[2] + 1, nk });
						visited[ny][nx][nk] = true;
					}
				}

			}
		}

		return -1;
	}

	public static boolean isValid(char pos, int key) {
		if (pos >= 'A' && pos <= 'F') {
			int bit = 1 << (pos - 'A');
			return (key & bit) != 0;
		}
		return true;
	}

	public static int getKey(char pos, int key) {
		if (pos >= 'a' && pos <= 'f') {
			int bit = 1 << (pos - 'a');
			return key | bit;
		}
		return key;
	}

}
