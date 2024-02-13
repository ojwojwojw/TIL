#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MAX = 1000000;

int solution(int n, vector<vector<int>> results) {
    int answer = n;
    
    vector<vector<int>> A (n,vector<int>(n,MAX));
    
    //2차원배열 A 초기화
    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j){
                A[i][j] = 0;
            }
        }
    }
    
    //results에 있는 데이터 입력해주기
    for (auto res : results){
        A[res[0]-1][res[1]-1] = 1;
        A[res[1]-1][res[0]-1] = -1;
    }
    
    //플로이드 와샬의 변형
    for (int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(A[i][k] == 1 && A[k][j] == 1){
                    A[i][j] = 1;
                    A[j][i] = -1;
                }
                else if (A[i][k] == -1 && A[k][j] == -1){
                    A[i][j] = -1;
                    A[j][i] = 1;
                }
            }
        }
    }
    
    //정답 체크해주기
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(A[i][j] == MAX){
                answer -- ;
                break;
            }
        }
    }
    
    return answer;
}