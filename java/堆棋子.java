import java.util.Arrays;
import java.util.Scanner;

public class 堆棋子 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++)
            x[i] = sc.nextInt();
        for (int i = 0; i < n; i++)
            y[i] = sc.nextInt();
        sc.close();
        int[] dis = new int[n];
        int[] result = new int[n];
        for (int i = 0; i < n; i++)
            result[i] = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dis[k] = Math.abs(x[k] - x[i]) + Math.abs(y[k] - y[j]);
                }
                Arrays.sort(dis);
                int temp = 0;
                for (int r = 0; r < n; r++) {
                    temp += dis[r];
                    result[r] = Math.min(temp, result[r]);
                }
            }
        }
        for(int i=0;i<n-1;i++)
            System.out.print(result[i]+" ");
        System.out.println(result[n-1]);

    }
}
