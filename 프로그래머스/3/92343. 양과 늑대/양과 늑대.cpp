#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> I;
vector<vector<int>> al (17,vector<int> {});
int answer = 0;

void dfs(int now ,int sheep, int wolf , vector<int> edges){
    if (I[now] == 0){
        sheep ++;
        answer = max(answer,sheep);
    }else{
        wolf ++;
    }
    
    if(sheep <= wolf){
        return;
    }
    
    vector<int> edges_copy (edges);
    
    for(auto edge : edges){
        vector<int> next_edges (al[edge]);
        
        for (auto x : edges){
            if (x != edge){
                next_edges.push_back(x);
            }
        }
        
        dfs(edge,sheep,wolf,next_edges);
    }
    
}


int solution(vector<int> info, vector<vector<int>> edges) {
    I = info;
    
    for (auto edge : edges){
        al[edge[0]].push_back(edge[1]);
    }
    
    dfs(0,0,0,al[0]);
    
    return answer;
}