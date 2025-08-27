class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        int n = schedules.length;    
        boolean isLate = false; 
        int inTime = 0;
        int desiredTime = 0;    
        int sat = 6 - startday ;
        int sun = 7 - startday ;
        
        if (sat < 0){
            sat += 7;
        }
         
        for (int i = 0 ; i < n ; i++){
            desiredTime = 60*(schedules[i]/100) + schedules[i] % 100;
            isLate = false;
            
            for(int j = 0 ; j < 7 ; j++){
                inTime = 60*(timelogs[i][j]/100) + timelogs[i][j] % 100;
                
                if(inTime - desiredTime > 10 && !(j == sat || j == sun)){
                    isLate = true; 
                    break;
                } 
            }

            if(isLate == false){
                answer++;
            }
            
        }
        
        return answer;
    }
}