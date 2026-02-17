class Solution {
    public int solution(int[] common) {
        int answer = 0;
        
        boolean isArithmetic = true;
        
        if(common[2] - common[1] !=  common[1] - common[0] ){
            isArithmetic = false;
        }
        
        if (isArithmetic){
            int d = common[1] - common[0];
            answer = common[common.length -1] + d;
        }else{
            int d = common[1] / common[0];
            answer = common[common.length -1]*d;
        }
        
        
        
        return answer;
    }
}