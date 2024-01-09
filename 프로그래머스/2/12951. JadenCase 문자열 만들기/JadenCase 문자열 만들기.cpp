#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char before =' ';
    char now = ' ';
    
    for (int i = 0 ; i<s.length();i++){
        if(before == ' ' && (65+32<= s[i] and s[i] < 65+32+26) ){
            now = s[i] - 32;
        }else if(before !=' ' && (65<=s[i]&& s[i] <65+26)){
            now = s[i] + 32;    
        }else{
            now = s[i];
        }
        
        answer += now;
        before = now;
    }
    
    
    
    return answer;
}