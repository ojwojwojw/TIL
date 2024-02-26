#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int A; // 노랑 가로
    int B; // 노랑 세로
    int temp_brown; // 임시로 연산한 갈색타일 개수
    
    //yellow의 약수 쌍들을 완전탐색하면 된다.
    for (int i = 1 ; i*i <= yellow ; i++){
        if(yellow % i != 0) continue; // 나누어 떨어지지 않는 경우는 버린다.
        A = yellow/i; //가로의 길이가 항상 세로보다 길거나 같다.
        B = i;
        temp_brown = 2*A + 2*B + 4;
        if(temp_brown == brown){
            answer = {A+2, B+2};
            break;
        }
    }
    
    
    return answer;
}