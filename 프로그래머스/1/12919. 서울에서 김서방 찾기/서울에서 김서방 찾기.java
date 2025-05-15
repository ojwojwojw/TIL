class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        int n = 0 ;
        
        for(int i=0 ; i<seoul.length;i++){
            if(seoul[i].equals("Kim")){
                System.out.println(seoul[i]);
                n = i;
            }
        }
        
        String s = Integer.toString(n);
        answer = "김서방은 "+s+"에 있다";
        
        return answer;
    }
}