#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    for(int i = 1 ; i < N ; i++){
        for (int j = 0 ; j < triangle[i].size() ;j++){
            if (j == 0){
                triangle[i][j] += triangle[i-1][j];
            } 
            else if (j == triangle[i].size() - 1){
                triangle[i][j] += triangle[i-1][j-1];
            }
            else{
                triangle[i][j] += max(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
    }
    
    for (int i = 0 ; i < N ; i++){
        answer = max(answer,triangle[N-1][i]);
    }
    return answer;
}