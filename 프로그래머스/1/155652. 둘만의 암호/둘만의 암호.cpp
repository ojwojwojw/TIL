#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    char now = ' ';
    int cnt;
    bool isSkip = false;
    
    for(char ch : s){
        now = ch;
        cnt = 1;
        while(cnt<=index){
            now++;
            if (now > 'z'){
                now -= 26;
            }

            isSkip = false;
            for(char sk : skip){
                if(now == sk){
                    isSkip = true;
                }
            }
            
            if(!isSkip){
                cnt++;
            }
        }
        answer += now;   
    }
     
    return answer;
}