import java.util.*;
import java.io.*;

class Solution {
    static class Pair {
        int x, y;
        Pair(int x, int y) { this.x = x; this.y = y; }
    }

    static int n, maxCore, minWire;
    static int[][] processor;
    static List<Pair> coreList;

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        StringBuilder sb = new StringBuilder();

        for (int test_case = 1; test_case <= T; test_case++) {
            n = Integer.parseInt(in.readLine());
            processor = new int[n][n];
            coreList = new ArrayList<>();

            maxCore = 0;
            minWire = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                for (int j = 0; j < n; j++) {
                    processor[i][j] = Integer.parseInt(st.nextToken());
                    if (processor[i][j] == 1) {
                        if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
                            coreList.add(new Pair(i, j));
                        }
                    }
                }
            }

            backtrack(0, 0, 0);
            sb.append("#").append(test_case).append(" ").append(minWire).append("\n");
        }

        System.out.println(sb);
    }

    public static void backtrack(int cnt, int connected, int wireLength) {
        if (cnt == coreList.size()) {
            if (connected > maxCore) {
                maxCore = connected;
                minWire = wireLength;
            } else if (connected == maxCore) {
                minWire = Math.min(minWire, wireLength);
            }
            return;
        }

        Pair core = coreList.get(cnt);
        int x = core.x, y = core.y;

        for (int d = 0; d < 4; d++) {
            int nx = x, ny = y;
            int wireCount = 0;
            boolean canConnect = true;

            while (true) {
                nx += dx[d];
                ny += dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if (processor[nx][ny] != 0) {
                    canConnect = false;
                    break;
                }
                wireCount++;
            }

            if (canConnect) {
                nx = x;
                ny = y;
                while (true) {
                    nx += dx[d];
                    ny += dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    processor[nx][ny] = 2;
                }

                backtrack(cnt + 1, connected + 1, wireLength + wireCount);

                nx = x;
                ny = y;
                while (true) {
                    nx += dx[d];
                    ny += dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    processor[nx][ny] = 0;
                }
            }
        }
        
        backtrack(cnt + 1, connected, wireLength);
    }
}