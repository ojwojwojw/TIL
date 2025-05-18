import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";  
        
        String [] strings = new String[numbers.length];
        
        for(int i = 0 ;i<numbers.length;i++){
            strings[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(strings,(a,b) -> (b+a).compareTo(a+b));
        
        //System.out.println(Arrays.toString(strings));
            
        for(int i = 0 ;i<numbers.length;i++){
            answer += strings[i];
        }
        
        
        if(strings[0].equals("0")){
            return "0";
        }
        
        return answer;
    }
}