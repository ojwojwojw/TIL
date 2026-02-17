import java.util.Arrays;

class Solution {
    public int solution(int[][] board) {
        int answer = 0;
        int N = board.length;
        
        int[][] delta = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){
                if (board[i][j] == 1){
                    for(int[] d : delta){
                        if(i+d[0] >= 0 && i+d[0] < N && j+d[1] >= 0 && j+d[1] < N && board[i+d[0]][j+d[1]] != 1) {
                            board[i+d[0]][j+d[1]] = 2; // 1로 하면 안됨 
                        }    
                    }
                }
            } 
        }
        
        //System.out.println(Arrays.deepToString(board));
        
        //안전지대 세기 
        for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){
                if (board[i][j] == 0){
                    answer++;
                    
                }
            } 
        }
        
        return answer;
    }
}