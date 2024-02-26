#include <string>
#include <vector>

using namespace std;

char mapp[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string solution(int n, int t, int m, int p) {
    string answer = "";
    string num_string = "";
    
    for (int i = 0 ; i < m*t ; i++){
        int num = i;
        if (i == 0){
            num_string += '0';
        }
        
        string temp_str = "";
        while(num > 0){
            temp_str = mapp[num%n] + temp_str;
            num = num/n;
        }
        num_string += temp_str;
    }
    
    for (int i = p-1 ; i<m*t; i+=m){
        answer += num_string[i];
    }
    
    return answer;
}