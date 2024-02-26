#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    //모든 칸의 개수 구하기
    int N = 0;
    for (int i=1 ; i<=n ; i++){
        N += i ;
    }
    
    vector<int> snail (N+1,-1); // 삼각형 초기화
    
    int cnt = 1; // 채워줘야 하는 수
    int idx = 1; // 현재 몇번째 칸인지
    int h = 1; // 현재 몇층인지
    bool upper = false; // 움직이는 방향
    
    while(cnt <= N){
        //현재 인덱스 숫자 채워주기
        snail[idx] = cnt;
        //왼쪽 아랫칸이 인덱스를 초과하지 않고 비어있다면
        if(!upper && idx + h <= N && snail[idx+h] == -1){
            idx += h;
            h++;
        }
        else{
            //바로 오른쪽 칸이 인덱스를 초과하지 않고 비어있다면
            if(idx + 1 <=N && snail[idx+1] == -1){
                idx ++;
            }
            else{
                //왼쪽 위 칸이 인덱스를 초과하지 않고 비어있다면
                if(0 < idx - h && snail[idx-h] == -1){
                    idx -= h;
                    h--;
                    upper = true;
                }else{
                    //올라가던 도중에 숫자가 있는칸을 만나면 다시 아래로 선회해주어야 한다.
                    if(snail[idx-h] != -1){
                        idx += h;
                        h++;
                        upper = false;
                    }
                }
            }
        }
        cnt ++;
    }
    
    for(int i = 1 ;i < snail.size() ;i++){
        answer.push_back(snail[i]);
    }
        
    return answer;
}