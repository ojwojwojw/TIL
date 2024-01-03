#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for(int i = left ; i <= right; i++){
        int cnt = 0;
        for (int d = 1 ;d*d <= i; d ++){
            if (d*d == i){
                cnt ++;
            }
            if (i%d == 0){
                cnt += 2;
            }
        }
        if (cnt%2){
            answer -= i;
        }else{
            answer += i;
        }
    }
    
    return answer;
}