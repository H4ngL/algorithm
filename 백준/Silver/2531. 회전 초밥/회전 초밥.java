//package samsung01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;


	public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		int[] arr = new int[n];
		
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		int[] visit = new int[d+1];
		
		int answer = 0; 
		
		
		int now = 0;
		for(int i = 0; i < k; i++) {
			if(visit[arr[i]] == 0) {
				now++;
			}		

			visit[arr[i]]++;
		}
		
		int start = 0;
		int end = k;
		int count = 0;
		
		while(count <= n) {
//			System.out.println(start);
			int isC = 0;
			if(visit[c] == 0) {
//				System.out.println("보너스");
				isC = 1;
			}
			answer = Math.max(answer, now + isC);

//			System.out.println(answer);
			
			visit[arr[start]]--;
//			System.out.println(visit[arr[start]]);
			if(visit[arr[start]] == 0) now--;
			
			if(visit[arr[end]] == 0) now++;
			visit[arr[end]]++;
						
			start = (start+1)%n;
			end = (end+1)%n;
			
			count++;
//			System.out.println();
		}
		System.out.println(answer);
		
		
	}

	

	

}





	
	
	
	
	
	
	
	
