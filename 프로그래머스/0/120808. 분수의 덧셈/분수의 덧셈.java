class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int[] answer = new int[2];
        
        int a = (numer1 * denom2 + numer2 * denom1) ;
        int b = denom1 * denom2;
        int c = GCD(a,b);
        
        answer[0] = a/c;
        answer[1] = b/c;
        
        return answer;
    }
    
    public int GCD (int num1 , int num2){
    if(num1 % num2 == 0 ){
        return num2;
    }
    
    return GCD(num2, num1%num2);
    
}
    
}


