class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        String A = String.valueOf(a);
        String B = String.valueOf(b);
        
        String AB = A+B;
        String BA = B+A;
        
        int ab = Integer.parseInt(AB);
        int ba = Integer.parseInt(BA);
        
        if (ab>=ba){
            answer = ab;
        }else{
            answer = ba;
        }
        
        return answer;
    }
}