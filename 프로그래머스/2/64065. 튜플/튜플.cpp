#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp (pair<int,int> &A ,pair<int,int> &B ){
    return A.second > B.second;
}


bool isNum (char ch){
    if(ch == '{' || ch == '}' || ch == ','){
        return false;
    }else{
        return true;
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> M;
    string temp = "";
    
    for(int i = 1 ; i < s.length() - 1 ; i++){
        if (!isNum(s[i-1])){
            temp = "";
        }
        
        if(temp != "" && (s[i] == '}' || s[i] == ',')){
            M[stoi(temp)]++;
            temp = "";
        }    
            
        if(isNum(s[i])){
            temp += s[i];
        }
    }
    
    vector<pair<int,int>> vec (M.begin(),M.end());
    sort(vec.begin(),vec.end(),cmp);
    for(auto x : vec){
        answer.push_back(x.first);
    }
    
    return answer;
}