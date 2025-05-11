class Solution {
    public String solution(String my_string, int n) {
        int m = my_string.length();
        
        String answer = "";
        
        for (int i = m-n ; i<m; i++ ){
            char ch = my_string.charAt(i);
            answer += ch;
        }
             
        return answer;
    }
}