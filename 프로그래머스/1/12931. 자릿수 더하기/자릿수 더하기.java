import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;

        String str = Integer.toString(n);
        
        for (int i = 0 ; i<str.length(); i++){
            char ch = str.charAt(i);
            int x = ch - '0';
            answer += x;
            
        }

        return answer;
    }
}