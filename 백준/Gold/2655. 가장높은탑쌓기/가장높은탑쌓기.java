import java.io.*;
import java.util.*;

public class Main {

    static class Brick {
        int index;
        int area;
        int height;
        int weight;

        Brick(int index, int area, int height, int weight) {
            this.index = index;
            this.area = area;
            this.height = height;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Brick[] bricks = new Brick[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int area = Integer.parseInt(st.nextToken());
            int height = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            bricks[i] = new Brick(i + 1, area, height, weight);
        }

        Arrays.sort(bricks, (b1, b2) -> b2.area - b1.area);

        int[] dp = new int[n];      
        int[] trace = new int[n];  
        Arrays.fill(trace, -1);

        int maxHeight = 0;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = bricks[i].height;
            for (int j = 0; j < i; j++) {
                if (bricks[j].weight > bricks[i].weight && dp[j] + bricks[i].height > dp[i]) {
                    dp[i] = dp[j] + bricks[i].height;
                    trace[i] = j;
                }
            }
            if (dp[i] > maxHeight) {
                maxHeight = dp[i];
                lastIndex = i;
            }
        }

        // 경로 역추적
        LinkedList<Integer> result = new LinkedList<>();
        while (lastIndex != -1) {
            result.add(bricks[lastIndex].index);
            lastIndex = trace[lastIndex];
        }

        // 출력
        System.out.println(result.size());
        for (int num : result) {
            System.out.println(num);
        }
    }
}
