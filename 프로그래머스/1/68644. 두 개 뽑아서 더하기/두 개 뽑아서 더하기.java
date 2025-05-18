import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        
        Set sums = new HashSet<>();
        
        for(int i=0 ;i<numbers.length;i++){
            for(int j=i+1 ;j<numbers.length;j++){
                sums.add(numbers[i]+numbers[j]);
            }       
        }
        
        System.out.println(sums); //잘 들어갔는지 디버깅은 어떻게 ? 
        
        //hashSet에 대한 정렬은 어떻게?
        List<Integer> list = new ArrayList<>(sums);
        Collections.sort(list);
        
        int[] answer = new int[list.size()];
        for(int i = 0 ; i<list.size() ; i++){
            answer[i] = list.get(i);
            
        }
        
        return answer;
    }
}