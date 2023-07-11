#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int idx1 = 0;
    int idx2 = 0;
    
    
    answer = "Yes";
    for(int i = 0 ; i < goal.size() ; i++){
        
        if(goal[i] == cards1[idx1]){
            idx1++;
        }
        else if(goal[i] == cards2[idx2]){
            idx2++;
        }
        else{
            answer = "No";
            break;
        }
    }
    
    
    
    
    return answer ;
}