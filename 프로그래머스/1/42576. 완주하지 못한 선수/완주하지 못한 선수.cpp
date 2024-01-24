#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string,int> hash;
    
    for(string player : participant){
        hash[player] ++;
    }
    
    for(string player : completion){
        hash[player] --;
    }
    
    for(auto player : hash){
        if(player.second > 0){
            answer = player.first;
            break;
        }
    }
    
    
    
    
    return answer;
}