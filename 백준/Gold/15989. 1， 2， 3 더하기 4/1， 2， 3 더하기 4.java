import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcase = Integer.parseInt(br.readLine());
		
		for(int t = 0; t < testcase; t++) {
			
			int n = Integer.parseInt(br.readLine());
			
			int oneNum = n;
			
			int count = useTwo(n);
			
			System.out.println(count);
			
		}
		

	}

	private static int useTwo(int n) {
		// TODO Auto-generated method stub
		
		int count = 0;
		while(n >= 0) {
			count++;
			count += useThree(n);
			n -= 2;	
		}
		return count;
		
	}

	private static int useThree(int n) {
		
		int count = 0;
		n = n-3;
		while(n >= 0) {
			count++;
			n -= 3;
		}
		
		return count;
	}

}
