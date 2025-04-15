import java.util.*;
import java.io.*;

public class Main {
	static int n, m, islandCnt, ans;
	static int[][] map;
	static boolean[][] visited;

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	static int[][] adj;
	static List<Edge> edges;
	static int[] parent;

	static class Edge implements Comparable<Edge> {
		int from, to, weight;

		Edge(int from, int to, int weight) {
			this.from = from;
			this.to = to;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge other) {
			return this.weight - other.weight;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		map = new int[n][m];
		visited = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		islandCnt = numbering();

		adj = new int[islandCnt + 1][islandCnt + 1];
		calMinDis();

		edges = new ArrayList<>();
		for (int i = 1; i <= islandCnt; i++) {
			for (int j = 1; j <= islandCnt; j++) {
				if (adj[i][j] != 0) {
					edges.add(new Edge(i, j, adj[i][j]));
				}
			}
		}

		Collections.sort(edges);

		parent = new int[islandCnt + 1];
		for (int i = 1; i <= islandCnt; i++) {
			parent[i] = i;
		}

		int connected = 0;

		for (Edge e : edges) {
			if (union(e.from, e.to)) {
				ans += e.weight;
				connected++;
				if (connected == islandCnt - 1)
					break;
			}
		}

		System.out.println(connected != islandCnt - 1 ? -1 : ans);
	}

	public static int numbering() {
		int num = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					bfs(i, j, num++);
				}
			}
		}

		return num - 1;
	}

	public static void bfs(int x, int y, int num) {
		Deque<int[]> queue = new ArrayDeque<>();
		queue.add(new int[] { x, y });
		visited[x][y] = true;
		map[x][y] = num;

		while (!queue.isEmpty()) {
			int[] cur = queue.poll();

			for (int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])
					continue;

				if (map[nx][ny] == 1) {
					queue.add(new int[] { nx, ny });
					visited[nx][ny] = true;
					map[nx][ny] = num;
				}
			}
		}
	}

	public static void calMinDis() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0) {
					int from = map[i][j];

					for (int d = 0; d < 4; d++) {
						int nx = i, ny = j, len = 0;

						while (true) {
							nx += dx[d];
							ny += dy[d];

							if (nx < 0 || ny < 0 || nx >= n || ny >= m)
								break;
							if (map[nx][ny] == from)
								break;

							if (map[nx][ny] == 0)
								len++;
							else {
								if (len >= 2) {
									int to = map[nx][ny];
									if (adj[from][to] == 0 || adj[from][to] > len) {
										adj[from][to] = len;
										adj[to][from] = len;
									}
								}
								break;
							}
						}
					}
				}
			}
		}
	}

	public static int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	public static boolean union(int a, int b) {
		int rootA = find(a);
		int rootB = find(b);

		if (rootA == rootB)
			return false;
		parent[rootB] = rootA;
		return true;
	}

}
