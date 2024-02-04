#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();
    queue<pair<int,int>> Q;
    vector<vector<bool>> visited (N,vector<bool>(M,false));
    
    Q.push({0,0});
    visited[0][0] = true;
    maps[0][0] = 1;

    while (Q.size()){
        
        if( maps[N-1][M-1] != 1){
            break;
        }
        
        int nowI = Q.front().first;
        int nowJ = Q.front().second;
        visited[nowI][nowJ] = true;
        Q.pop();

        for (int d = 0 ; d < 4; d++){
            int newI = nowI + dx[d];
            int newJ = nowJ + dy[d];
            if (newI < 0 || newI >= N || newJ <0 || newJ >=M){
                continue;
            }
            if (visited[newI][newJ] == true){
                continue;
            }
            if (maps[newI][newJ] == 0){
                continue;
            }
            
            maps[newI][newJ] = maps[nowI][nowJ] + 1;
            visited[newI][newJ] = true;
            Q.push({newI,newJ});
            
        }
    }
        
    answer = maps[N-1][M-1];
    if(answer == 1){
        answer = -1;
    }
    return answer;
}