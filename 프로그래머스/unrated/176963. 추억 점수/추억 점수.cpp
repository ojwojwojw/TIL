#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(int a = 0 ; a < photo.size() ; a++){
        answer.push_back(0);
    }
    
    
    
    // cout << photo.size()<< endl;
    // cout << photo[1].size() <<endl;
    for (int i = 0; i < photo.size(); i++) {
        for (int j = 0 ; j < photo[i].size(); j++){
            // cout << photo[i][j] << endl;
            for (int k = 0 ; k< name.size(); k++){
                if(photo[i][j]  ==  name[k]){
                    answer[i] += yearning[k];
                }
            }
            
        }
        cout << endl;
    }
    
    
    return answer;
}