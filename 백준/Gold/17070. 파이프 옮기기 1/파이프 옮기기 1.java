import java.io.*;
import java.util.*;
public class Main {
    static int moyang = 0; // 0 = 가로, 1 = 대각, 2 = 세로
    static int n;
    static Queue<Point> q;
    static int data[][];
    public static void main(String[] args) throws IOException{
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        data = new int[n][n];
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine()," ");
            for(int j =0; j<n; j++){
                data[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        q = new ArrayDeque<>();
        q.add(new Point(0,1,0));
        int cnt=0;
        while(!q.isEmpty()){
            Point p = q.poll();
            int x = p.x;
            int y = p.y;
            int shape = p.moyang;
            if(x==n-1&&y==n-1){
                cnt++;
                continue;
            }
            if(shape==0){
                moveToGaro(x,y);
                moveToDaegak(x,y);
            }else if(shape==1){
                moveToGaro(x,y);
                moveToSaero(x,y);
                moveToDaegak(x,y);
            }else if(shape==2){
                moveToSaero(x,y);
                moveToDaegak(x,y);
            }

        }
        System.out.println(cnt);
    }

    private static void moveToSaero(int x, int y) {
        int nx = x+1;
        int ny = y;
        if(isvalid(nx,ny)){
            q.add(new Point(nx,ny,2));
        }
    }

    private static void moveToDaegak(int x, int y) {
        int nx = x+1;
        int ny = y+1;
        if(isvalid(nx,ny)){
            if(data[x][y+1]==0&&data[x+1][y]==0){
                q.add(new Point(nx,ny,1));
            }
        }
    }

    private static void moveToGaro(int x, int y) {
        int nx = x;
        int ny = y+1;
        if(isvalid(nx,ny)){
            q.add(new Point(nx,ny,0));
        }
    }

    private static boolean isvalid(int nx, int ny) {
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&data[nx][ny]==0){
            return true;
        }
        return false;
    }

    static class Point {
        int x;
        int y;
        int moyang;

        Point(int x, int y, int moyang) {
            this.x = x;
            this.y = y;
            this.moyang = moyang;
        }
        public String toString(){
            return  x +" "+y+" "+moyang;
        }
    }

}