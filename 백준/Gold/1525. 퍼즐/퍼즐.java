
import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


	public class Main {
		
	static int[] dy = {-1, 0, 1, 0};
	static int[] dx = {0, 1, 0, -1};

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int answer = 123456789;
		
		Map<Integer, Integer> map = new HashMap<>();
		Queue<Integer> q = new ArrayDeque<Integer>();
		
		int num = 0;
		
		for(int i = 0; i < 3; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 3; j++) {
				int now = Integer.parseInt(st.nextToken());
				if(now == 0) now = 9;
				num = num*10 + now;
			}
		}
		
		if(answer == num) {
			System.out.println(0);
			return;
		}
		
		map.put(num, 0);
		q.offer(num);
		while(!q.isEmpty()) {
			
			int now = q.poll();
			
			String str = String.valueOf(now);
			
			for(int i = 0; i < 9; i++) {
				if(str.charAt(i) == '9') {
					int y = i / 3;
					int x = i % 3;
						
					for(int d = 0; d < 4; d++) {
						int ny = y + dy[d];
						int nx = x + dx[d];
						
						if(ny < 0 || nx < 0 || nx >= 3 || ny >= 3) continue;
						StringBuilder bstr = new StringBuilder(str);
						char temp = str.charAt(i);
						bstr.setCharAt(i, bstr.charAt(ny*3 + nx));
						bstr.setCharAt(ny*3 + nx, temp);
						int nextNum = Integer.parseInt(bstr.toString());
						
						if(map.containsKey(nextNum)) continue;
						
						if(answer == nextNum) {
							System.out.println(map.get(now) + 1);
							return;
						}
						else {
							q.offer(nextNum);
							map.put(nextNum, map.get(now)+1);
						}
						
					}
					break;
				}
			}
		}
		System.out.println(-1);
		
	}
}





	
	
	
	
	
	
	
	
