#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector <char> ST;
    
    for (char ch : s){
        if (ST.size() == 0){
            ST.push_back(ch);
        }else{
            if(ch == '('){
            ST.push_back(ch);
            }

            if(ch == ')' && ST[ST.size()-1] == '('){
                ST.pop_back();
            }
        }
        
        // for(char ch : ST){
        //     cout<< ch <<" ";
        // }
        // cout<< endl;
    }

    if(ST.size()>0){
        answer = false;
    }else{
        answer = true;
    }
    
    return answer;
}