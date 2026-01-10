import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 1. 입력 받기
        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N + 1]; // 상담 소요 시간
        int[] P = new int[N + 1]; // 상담 수익
        
        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
        }

        // 2. DP 배열 생성 (N+2 크기로 만들어야 dp[i+1] 참조 시 에러가 안 남)
        int[] dp = new int[N + 2];

        // 3. 뒤에서부터 계산 (역방향 DP)
        for (int i = N; i >= 1; i--) {
            int nextDay = i + T[i]; // 오늘 상담을 할 경우 끝나는 날짜

            if (nextDay <= N + 1) {
                // [상담을 할 수 있는 경우]
                // 1) 오늘 상담 수익 + 상담이 끝난 날의 최대 수익: P[i] + dp[nextDay]
                // 2) 오늘 상담 안 하고 내일의 최대 수익을 가져옴: dp[i+1]
                dp[i] = Math.max(P[i] + dp[nextDay], dp[i + 1]);
            } else {
                // [상담을 할 수 없는 경우] (퇴사일을 넘김)
                // 오늘 상담은 포기하고, 내일의 최대 수익을 그대로 가져옴
                dp[i] = dp[i + 1];
            }
        }

        // 4. 결과 출력 (1일부터의 최대 수익)
        System.out.println(dp[1]);
    }
}