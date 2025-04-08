import java.util.*;
import java.io.*;

class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();

		for (int test_case = 1; test_case <= T; test_case++) {
			int n = Integer.parseInt(in.readLine());
			List<Integer> list = new ArrayList<>();
			
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int i = 0; i < n; i++) {
				int num = Integer.parseInt(st.nextToken());
				
				if(list.isEmpty() || list.get(list.size() - 1) < num) {
					list.add(num);
				} else {
					int idx = lower_bound(list, num);
					list.set(idx, num);
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(list.size()).append("\n");
		}
		
		System.out.println(sb);
	}
	
	public static int lower_bound(List<Integer> list, int target) {
		int l = 0, r = list.size();
		
		while(l < r) {
			int mid = (l + r) / 2;
			
			if(list.get(mid) >= target) r = mid;
			else l = mid + 1;
		}
		
		return r;
	}
}