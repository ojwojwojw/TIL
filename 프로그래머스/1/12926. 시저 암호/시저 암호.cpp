#include <string>
#include <vector>

using namespace std;

char Change(char x , int n){
    if ( x == ' '){
        return ' ';
    }
    if ('a' <= x && x <= 'z' && x + n > 'z'){
        return x + n - 26;
    }
    if ('A' <= x && x <= 'Z' && x + n > 'Z'){
        return x + n - 26;
    }
    
    return x + n ;

}

string solution(string s, int n) {
    string answer = "";
    for (char x : s){
        answer += Change(x, n);
    }    
    return answer;
}