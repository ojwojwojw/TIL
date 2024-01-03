#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    //중복되는 원소를 지우고 시작해야, 
    //그리디 도중에 중복되는 학생이 옷을 나누어주는 연산이 일어나지 않는다.
    for (int i = 0 ; i < reserve.size() ;i++){
        for (int j = 0 ; j < lost.size() ; j++){
            if (reserve[i] == lost[j]){
                reserve.erase(reserve.begin()+i);
                lost.erase(lost.begin()+j);
                i = -1;
                break;
            }
        }
    }
    
    int answer = n - lost.size();
    //그리디를 위한 이상적인 입력이 들어온다는 보장이 없으므로 정렬
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
     
    for (int i = 0 ; i < reserve.size() ;i++){
        for (int j = 0 ; j < lost.size() ; j++){

            if (reserve[i] + 1 == lost[j]){
                lost.erase(lost.begin()+j);
                answer += 1;
                break;
            }
                
            else if (reserve[i] - 1 == lost[j]){
                lost.erase(lost.begin()+j);
                answer += 1;
                break;
            } 
        }   
    }
    return answer;
}