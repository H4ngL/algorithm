import java.util.*;
import java.io.*;

public class Main {

	static int n, m, ans;
	static int[][] map;
	static List<int[]> chicken;
	static List<int[]> choose;
	static List<int[]> home;

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ans = Integer.MAX_VALUE;

		map = new int[n][n];
		chicken = new ArrayList<int[]>();
		choose = new ArrayList<int[]>();
		home = new ArrayList<int[]>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1)
					home.add(new int[] { i, j });
				if (map[i][j] == 2)
					chicken.add(new int[] { i, j });
			}
		}

		comb(0, 0);
		System.out.println(ans);
	}

	public static void comb(int cnt, int start) {
		if (cnt == m) {
			ans = Math.min(ans, cal());
			return;
		}

		for (int i = start; i < chicken.size(); i++) {
			choose.add(chicken.get(i));
			comb(cnt + 1, i + 1);
			choose.remove(choose.size() - 1);
		}
	}

	public static int cal() {
		int ret = 0;
		
		for(int[] h : home) {
			int dis = Integer.MAX_VALUE;
			for(int[] c : choose) {
				dis = Math.min(dis, calDis(h, c));
			}
			ret += dis;
		}
		
		return ret;
	}

	public static int calDis(int[] a, int[] b) {
		return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
	}
}
