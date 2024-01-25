#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    unordered_map <char,pair<int,int>> hash; //string이 아님에 주의
    string DAT[10] = {"",};
    
    for(char x : X){
        hash[x].first ++;
    }

    for(char y : Y){
        hash[y].second ++;
    }

    for(auto data : hash){
        if(data.second.first && data.second.second){
            int x = min( data.second.first,data.second.second);
            for (int i = 0 ; i < x; i++){
                  DAT[data.first - '0'] += data.first ;
            }
        }
    }
    
//     for (int i = 0 ;i<10;i++){
//      cout<<DAT[i]<<endl;
//     }
    bool onlyZero = true;
    for (int i = 1 ; i<10; i++){
        if(DAT[i] != ""){
            onlyZero = false;
        }
    }
    
    for(int i = 0; i < 10; i++){
        answer = DAT[i] + answer;
    }
    
    

    
    if(answer == ""){
        answer = "-1";
    }else{
        if (onlyZero){
            answer = "0";
        }
    }
    
    
    return answer;
}