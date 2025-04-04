import java.io.*;
import java.util.*;
 
public class Solution {
    static class User {
        int id, time;
        int receptionNum, repairNum;
        int startTimeReception = -1;
        int startTimeRepair = -1;
 
        public User(int id, int time) {
            this.id = id;
            this.time = time;
        }
    }
 
    static int n, m, k, a, b;
    static int[] ta, tb, tk;
    static User[] reception, repair;
    static Deque<User> waitReception, waitRepair, finished;
    static List<User> users;
 
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(in.readLine());
 
        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
 
            ta = new int[n + 1];
            st = new StringTokenizer(in.readLine());
            for (int i = 1; i <= n; i++) {
                ta[i] = Integer.parseInt(st.nextToken());
            }
 
            tb = new int[m + 1];
            st = new StringTokenizer(in.readLine());
            for (int i = 1; i <= m; i++) {
                tb[i] = Integer.parseInt(st.nextToken());
            }
 
            tk = new int[k + 1];
            users = new ArrayList<>();
            st = new StringTokenizer(in.readLine());
            for (int i = 1; i <= k; i++) {
                tk[i] = Integer.parseInt(st.nextToken());
                users.add(new User(i, tk[i]));
            }
 
            reception = new User[n + 1];
            repair = new User[m + 1];
            waitReception = new ArrayDeque<>();
            waitRepair = new ArrayDeque<>();
            finished = new ArrayDeque<>();
 
            users.sort(Comparator.comparingInt(u -> u.time));
            simulate();
 
            int result = 0;
            for (User u : finished) {
                if (u.receptionNum == a && u.repairNum == b) {
                    result += u.id;
                }
            }
 
            if (result == 0)
                result = -1;
            sb.append("#").append(test_case).append(" ").append(result).append("\n");
        }
 
        System.out.print(sb);
    }
 
    static void simulate() {
        int time = 0;
        int cnt = 0;
        int userIdx = 0;
 
        while (cnt < k) {
            // 1. 접수 대기열에 넣기
            while (userIdx < users.size() && users.get(userIdx).time == time) {
                waitReception.add(users.get(userIdx));
                userIdx++;
            }
 
            // 2. 접수 -> 정비
            for (int i = 1; i <= n; i++) {
                User u = reception[i];
                if (u != null && time - u.startTimeReception == ta[i]) {
                    waitRepair.add(u);
                    reception[i] = null;
                }
            }
 
            // 3. 정비 -> 완료
            for (int i = 1; i <= m; i++) {
                User u = repair[i];
                if (u != null && time - u.startTimeRepair == tb[i]) {
                    finished.add(u);
                    repair[i] = null;
                    cnt++;
                }
            }
 
            // 4. 접수 창구 배정
            for (int i = 1; i <= n; i++) {
                if (reception[i] == null && !waitReception.isEmpty()) {
                    User u = waitReception.poll();
                    u.receptionNum = i;
                    u.startTimeReception = time;
                    reception[i] = u;
                }
            }
 
            // 5. 정비 창구 배정
            for (int i = 1; i <= m; i++) {
                if (repair[i] == null && !waitRepair.isEmpty()) {
                    User u = waitRepair.poll();
                    u.repairNum = i;
                    u.startTimeRepair = time;
                    repair[i] = u;
                }
            }
 
            time++;
        }
    }
}