#include <string>
#include <vector>

using namespace std;
bool visited[100][100];
int start[2];
int goal[2];
int n[2];
int N,M;
int ans = 100000000;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(vector<string> &board){
    vector<vector<int>> Q ;
    vector<int> now ;
    int cnt = 0;
    
    
    Q.push_back({start[0],start[1],cnt});
    visited[start[0]][start[1]] = true;
    
    while(!Q.empty()){
        now = Q.front();
        Q.erase(Q.begin());
        
        if (board[now[0]][now[1]] == 'G'){
            ans = min(now[2],ans);
        }
        
        for(int d = 0 ; d<4; d++){
            n[0] = now[0] + dx[d];
            n[1] = now[1] + dy[d];    
            
            if ((0<=n[0]&&n[0]<N) && (0<=n[1]&&n[1]<M) && (board[n[0]][n[1]]!='D')){
                
                while(true){
                    n[0] += dx[d];
                    n[1] += dy[d];
                    if(n[0]<0 || n[0]>=N || n[1]<0 || n[1]>=M || board[n[0]][n[1]] == 'D'){
                        n[0] -= dx[d];
                        n[1] -= dy[d];  
                        break;           
                    }
                }
            
                if(!visited[n[0]][n[1]]){
                    Q.push_back({n[0],n[1],now[2]+1});
                    visited[n[0]][n[1]] = true;
                }

            }
            
        }
        
              
    }

}


int solution(vector<string> board) {

    N = board.size();
    M = board[0].length();
    
    
    for (int i = 0 ; i<N ; i++){
        for(int j = 0 ; j<M ; j++){
            if(board[i][j] == 'R'){
                start[0] = i;
                start[1] = j;
            }
            if(board[i][j] == 'G'){
                goal[0] = i;
                goal[1] = j;
            }
        }
    }
    
    bfs(board);
    if (ans == 100000000) return -1;
    return ans;
}