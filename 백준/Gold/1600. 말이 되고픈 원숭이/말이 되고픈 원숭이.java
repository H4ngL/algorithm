import java.util.*;
import java.io.*;

public class Main {
	static class Cur {
		int x, y;
		int k;
		int rank;

		Cur(int x, int y, int k, int rank) {
			this.x = x;
			this.y = y;
			this.k = k;
			this.rank = rank;
		}
	}

	static int k, n, m, ans;
	static int[][] map;
	static boolean[][][] visited; 

	static int[] dx = { -1, 1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2 };
	static int[] dy = { 0, 0, -1, 1, 1, 2, 2, 1, -1, -2, -2, -1 };

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		k = Integer.parseInt(in.readLine());

		StringTokenizer st = new StringTokenizer(in.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		map = new int[n][m];
		visited = new boolean[n][m][k + 1];
		
		ans = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		if (n == 1 && m == 1) {
		    System.out.println(0);
		    return;
		}

		bfs(0, 0);
		System.out.println(ans == Integer.MAX_VALUE ? -1 : ans); 
	}

	public static void bfs(int x, int y) {
		Deque<Cur> queue = new ArrayDeque<>();
		queue.add(new Cur(x, y, k, 0));
		visited[x][y][k] = true;

		while (!queue.isEmpty()) {
			Cur c = queue.poll();
			
			for(int i = 0; i < 12; i++) {
				if(i >= 4 && c.k <= 0) break;
				
				int nx = c.x + dx[i];
				int ny = c.y + dy[i];
				int nk = (i >= 4) ? c.k - 1 : c.k;
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 1) continue;
				
				if(nx == n - 1 && ny == m - 1) {
					ans = c.rank + 1;
					return;
				}
				
				if (!visited[nx][ny][nk]) {
					visited[nx][ny][nk] = true;
					queue.add(new Cur(nx, ny, nk, c.rank + 1));
				}
			}
		}
	}

}
