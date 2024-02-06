#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 간선 구조체
struct Edge{
    int to;
    int cost;
};

vector<Edge> al [201]; //인접리스트
int N; //노드의 개수
int dijkstra(int start,int end){
    
    //dist
    int dist[201] = {0,};
    int maxV = 398000000;
    for (int i = 0; i < N+1; i++){
        if(i != start){
            dist[i] = maxV;
        }
    }
    
    //visited
    bool visited[201] = {false,};
    
    //모든 노드를 순회 1 ~ N 만큼 반복
    for(int i = 0 ; i < N+1; i++){
        //dist에서 최솟값을 갖는 노드 찾기    
        int min_cost = 398000000;
        int now = -1 ;
        for (int j = 0; j < N+1 ; j++){
           //cout<< j <<endl;
           if (dist[j] < min_cost && !visited[j]){
               min_cost = dist[j];
               now = j;
           }
        }
        //cout << now << endl;
        //cout << endl;
        
        //visited 갱신
        visited[now] = true;
        
        //현재 노드에서 연결된 다음 노드를 보면서, 필요하면 dist를 갱신해준다
        for(auto &next : al[now]){
            int n_cost = dist[now] + next.cost;
            if (n_cost < dist[next.to]){
                dist[next.to] = n_cost;
            }
        }
        

        
    }
    // for (int k = 0 ; k< N+1 ; k++){
    //     cout<<k<<"까지의 최소비용: "<<dist[k]<<endl;
    // }
    // cout<<endl;
    
    return dist[end];
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    N = n;
    
    //인접 리스트를 양방향 그래프로 채우기
    for(auto fare : fares){
        al[fare[0]].push_back({fare[1],fare[2]});
        al[fare[1]].push_back({fare[0],fare[2]});
    }
    
    answer = 398000000;
    for (int i = 0 ; i < N+1 ;i++){
        answer = min(answer,dijkstra(s,i)+dijkstra(i,a)+dijkstra(i,b));
    }
    
    return answer;
}