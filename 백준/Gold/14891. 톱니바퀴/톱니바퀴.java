import java.util.*;
import java.io.*;

class Main {
	static List<int[]> magnets;
	static int[] flag;

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		magnets = new ArrayList<>();
		flag = new int[4];

		for (int i = 0; i < 4; i++) {
			int[] magnet = new int[8];
			String str = in.readLine();
			for (int j = 0; j < 8; j++) {
				magnet[j] = str.charAt(j) - '0';
			}
			magnets.add(magnet);
		}

		
		int k = Integer.parseInt(in.readLine());
		for (int i = 0; i < k; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int idx = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());
			rotate(idx - 1, dir);
		}

		System.out.println(calScore());
	}

	public static void rotate(int idx, int dir) {
		int[] newFlag = flag.clone();
		newFlag[idx] = ((flag[idx] - dir) + 8) % 8;

		// 왼쪽 전파
		int curDir = dir;
		for (int i = idx - 1; i >= 0; i--) {
			int right = magnets.get(i + 1)[(flag[i + 1] + 6) % 8];
			int left = magnets.get(i)[(flag[i] + 2) % 8];

			if (right == left)
				break;

			curDir = -curDir;
			newFlag[i] = ((flag[i] - curDir) + 8) % 8;
		}

		// 오른쪽 전파
		curDir = dir;
		for (int i = idx + 1; i < 4; i++) {
			int left = magnets.get(i - 1)[(flag[i - 1] + 2) % 8];
			int right = magnets.get(i)[(flag[i] + 6) % 8];

			if (right == left)
				break;

			curDir = -curDir;
			newFlag[i] = ((flag[i] - curDir) + 8) % 8;
		}

		flag = newFlag;
	}

	public static int calScore() {
		int a = magnets.get(0)[flag[0]] == 1 ? 1 : 0;
		int b = magnets.get(1)[flag[1]] == 1 ? 2 : 0;
		int c = magnets.get(2)[flag[2]] == 1 ? 4 : 0;
		int d = magnets.get(3)[flag[3]] == 1 ? 8 : 0;
		return a + b + c + d;
	}
}