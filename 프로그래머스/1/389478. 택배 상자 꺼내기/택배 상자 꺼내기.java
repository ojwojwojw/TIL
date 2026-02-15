class Solution {
    public int solution(int n, int w, int num) {
        // 1. 목표 상자(num)의 층(row)과 열(col) 구하기 (0부터 시작한다고 가정)
        int targetRow = (num - 1) / w;
        int targetCol = (targetRow % 2 == 0) 
                        ? (num - 1) % w             // 짝수 층: 왼쪽 -> 오른쪽
                        : (w - 1) - ((num - 1) % w); // 홀수 층: 오른쪽 -> 왼쪽

        // 2. 전체 상자(n)의 층(row)과 열(col) 구하기
        int totalRow = (n - 1) / w;
        int totalCol = (totalRow % 2 == 0) 
                        ? (n - 1) % w 
                        : (w - 1) - ((n - 1) % w);

        // 3. 기본적으로 꺼내야 하는 높이는 (전체 층 - 목표 층 + 1)
        int answer = totalRow - targetRow + 1;

        // 4. [예외 처리] 만약 맨 위층(totalRow)에 상자가 목표 열(targetCol)까지 안 쌓였다면?
        // 지그재그 방향에 따라 '비어있는 곳'인지 체크
        if (totalRow % 2 == 0) { // 맨 위가 순방향(R)일 때
            if (targetCol > totalCol) answer--; 
        } else { // 맨 위가 역방향(L)일 때
            if (targetCol < totalCol) answer--;
        }

        return answer;
    }
}