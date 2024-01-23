#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> ST;
    int N = board[0].size();
    int doll = 0;
    
    
    for(int move : moves){
        for(int depth = 0 ; depth < N ; depth++){
            if(board[depth][move-1]){
                doll = board[depth][move-1];
                ST.push_back(doll);
                if(ST.size() >= 2 && ST[ST.size()-2] == doll){
                    ST.pop_back();
                    ST.pop_back();
                    answer += 2;
                }
                board[depth][move-1] = 0;
                break;
            }
        }
    }
    
    
    return answer;
}