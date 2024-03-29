#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    int N = strlen(t);
    int M = strlen(p);
    int same = 0;
    int k = 0;
    
    for(int i = 0 ; i <= N-M ;i++){
        k = 0;
        same = 0 ;
        for(int j = i ; j < i+M ;j++){
            if(t[j] < p[k]){
                answer ++;
                break;
            }
            else if (t[j] > p[k]){
                break;
            }
            else if (t[j] == p[k]){
                same ++;
            }
            k++;
        }
        
        if(same == M){
            printf("%d\n",same);
            answer ++;
        }

    }
    
    return answer;
}