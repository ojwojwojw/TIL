class Solution {
    public int[] solution(long n) {
        
        String s = String.valueOf(n); 
        int N = s.length();
        int[] answer = new int[N];
        
        for(int i=0 ; i<N ; i++){
            System.out.println(s.substring(N-1-i,N-i));
            answer[i] = Integer.parseInt(s.substring(N-1-i,N-i));     
        }
             
        return answer;
    }
}