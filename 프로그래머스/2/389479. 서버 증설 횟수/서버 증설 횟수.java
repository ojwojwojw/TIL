class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] addedAt = new int[24]; // i시간에 '새로' 증설한 서버 대수
        int currentRunning = 0;      // 현재 운영 중인 증설 서버 총합

        for (int i = 0; i < 24; i++) {
            // 1. 만료된 서버 회수 (i-k 시점에 추가했던 서버들)
            if (i >= k) {
                currentRunning -= addedAt[i - k];
            }

            // 2. 현재 필요한 총 증설 서버 대수 계산
            // players[i]가 2*m 이라면 총 2대가 필요함
            int totalNeeded = players[i] / m;

            // 3. 부족한 만큼 추가 증설
            if (currentRunning < totalNeeded) {
                int diff = totalNeeded - currentRunning;
                addedAt[i] = diff;   // i시간에 diff대 증설 기록
                answer += diff;      // 총 증설 횟수 누적
                currentRunning += diff; // 현재 운영 서버에 반영
            }
        }
        return answer;
    }
}