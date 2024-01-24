#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int N = participant.size();
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    completion.push_back("##dummy!@#");
    
    // abcd abc
    // aaabb aabb
    
    for(int i = 0;i< N;i++){
        if(participant[i]!=completion[i]){
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}