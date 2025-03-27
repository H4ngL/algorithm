import java.util.*;
import java.io.*;

// 4 2 4 4 1

public class Main {
	
	static class Cctv {
		int x, y;
		int type;
		
		public Cctv(int x, int y, int type) {
			super();
			this.x = x;
			this.y = y;
			this.type = type;
		}
	}
	
	static int n, m;
	static int ans = Integer.MAX_VALUE;
	static int[][] office;
	static List<Cctv> cctvList;
	
    static int[][][] directions = { 
            {}, 
            {{0}, {1}, {2}, {3}}, // 1번 CCTV (한 방향)
            {{0, 2}, {1, 3}}, // 2번 CCTV (서로 반대 방향)
            {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, // 3번 CCTV (직각 방향)
            {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, // 4번 CCTV (3방향)
            {{0, 1, 2, 3}} // 5번 CCTV (전 방향)
    };

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		office = new int[n][m];
		cctvList = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			for(int j = 0; j < m; j++) {
				office[i][j] = Integer.parseInt(st.nextToken());
				if(office[i][j] >= 1 && office[i][j] <= 5) {
					cctvList.add(new Cctv(i, j, office[i][j]));
				}
			}
		}
		
		comb(0);
		System.out.println(ans);
	}
	
	static public void comb(int cnt) {
		if(cnt == cctvList.size()) {
			ans = Math.min(ans, check());
			return;
		}
		
		Cctv cctv = cctvList.get(cnt);
		int[][] backup = copyOffice();
		
		for(int[] dirSet : directions[cctv.type]) {
			monitor(cctv.x, cctv.y, dirSet);
			comb(cnt + 1);
			restoreOffice(backup);
		}
	}
	
	static public void monitor(int x, int y, int[] dirSet) {
		for(int d : dirSet) {
			int nx = x, ny = y;
			while(true) {
				nx += dx[d];
				ny += dy[d];
				
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || office[nx][ny] == 6) break;
				if (office[nx][ny] == 0) office[nx][ny] = -1; 
			}
		}
	}
	
	static int[][] copyOffice() {
        int[][] copy = new int[n][m];
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
            	copy[i][j] = office[i][j];
            }
        }
        return copy;
    }
	
	static public void restoreOffice(int[][] backup) {
		for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
            	office[i][j] = backup[i][j];
            }
        }
	}
	
	static public int check() {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(office[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}
}
