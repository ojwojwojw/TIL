#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector <int> ST ;
    vector <bool> visited (n,false);
    int v ; // 지금 탐색하고 있는 노드
    
    for (int i = 0 ; i < n ; i++){
        
        if (visited[i] == false){
            ST.push_back(i);
            answer++;
            visited[i] = true;
            
            while(ST.size() > 0){
                
                v = ST.back();
                ST.pop_back();
                for (int j = 0 ; j < n ; j++){
                    if (visited[j] == false && computers[v][j] == 1){
                        ST.push_back(j);
                        visited[j] = true;
                    }   
                }
            }
        }
    }

    
    return answer;
}