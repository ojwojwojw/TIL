#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    unordered_map <int,int> Priority; 
    vector<int> Queue;
    
    for (int i = 0 ; i<priorities.size(); i++){
        Priority[i] = priorities[i];
        Queue.push_back(i);
    }
    
    while(true){
        int now = Queue.front();
        bool canPop = true;
        Queue.erase(Queue.begin());
        for (int x : Queue){
            if(Priority[now] < Priority[x]){
                canPop = false;
                break;
            }    
        }
        
        if(canPop){
            answer++;    
        }else{
            Queue.push_back(now);
        }
        
        if(canPop && now == location){
            break;
        }
    }
    
    return answer;
}