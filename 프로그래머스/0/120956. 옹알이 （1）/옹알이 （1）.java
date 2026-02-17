class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        
        String[] can = { "aya", "ye", "woo", "ma"};
        
        
        for (String b : babbling){
            for (String c : can ){
                b = b.replace(c,"#");   
            }
            
            b = b.replace("#","");
            if (b.length() == 0) answer ++;
        }

        
        return answer;
    }
}