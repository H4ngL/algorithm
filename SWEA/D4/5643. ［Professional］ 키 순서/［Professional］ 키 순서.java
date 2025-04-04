import java.util.*;
import java.io.*;

class Solution {
	static int n, m;
	static int[] in;
	static int[] out;
	static List<Integer>[] adj;

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();

		for (int test_case = 1; test_case <= T; test_case++) {
			n = Integer.parseInt(br.readLine());
			m = Integer.parseInt(br.readLine());

			adj = new ArrayList[n + 1]; 
			for (int i = 0; i <= n; i++) {
				adj[i] = new ArrayList<>(); 
			}

			for (int i = 0; i < m; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				adj[a].add(b);
			}

			in = new int[n + 1];
			out = new int[n + 1];

			update();

			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (in[i] + out[i] == n - 1)
					cnt++;
			}

			sb.append("#").append(test_case).append(" ").append(cnt).append("\n");
		}

		System.out.println(sb);
	}

	public static void update() {
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			boolean[] visited = new boolean[n + 1];

			Deque<Integer> queue = new ArrayDeque<>();
			queue.add(i);
			visited[i] = true;

			while (!queue.isEmpty()) {
				int cur = queue.poll();

				for (int node : adj[cur]) {
					if (!visited[node]) {
						queue.add(node);
						visited[node] = true;
						in[node]++;
						cnt++;
					}
				}
			}

			out[i] = cnt;
		}
	}
}