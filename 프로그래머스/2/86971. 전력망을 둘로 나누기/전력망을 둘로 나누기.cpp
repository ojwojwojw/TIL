#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    int N = wires.size();
    
    for(int i = 0 ; i < N; i++){
        vector<vector<int>> al(n+1,vector<int>(0,{}));
        for(int j = 0 ; j < N; j++){
            if(i != j){
                al[wires[j][0]].push_back(wires[j][1]);
                al[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        vector <bool> visited (n+1,false);
        int temp_ans = 0;
        for (int j = 1 ; j <= n; j++){
           if (!visited[j]){
                int cnt = 0;
                vector <int> ST;
                ST.push_back(j);
                visited[j] = true;
                while(!ST.empty()){
                    int now = ST.back();
                    ST.pop_back();
                    for(int k = 0 ; k < al[now].size() ;k++){
                        if(! visited[al[now][k]]){
                            ST.push_back(al[now][k]);
                            visited[al[now][k]] = true;
                            cnt++;
                        }
                    }    
               }
               temp_ans = abs(cnt-temp_ans);
           }
        }
        answer=min(temp_ans,answer);
        
    }
    
    return answer;
}