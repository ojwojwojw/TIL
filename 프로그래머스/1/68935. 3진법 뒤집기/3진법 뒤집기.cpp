#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    string base_3 = "";
    while(n > 0){
        base_3 += (n % 3) + '0';
        n = n/3;
    }
    //cout << base_3;
    int L = base_3.length() - 1;
    int T = 1;
    for (int i = L ; i>=0 ; i--){
        answer += (base_3[i]  - '0')*T;
        T *= 3;
        }
    
    return answer;
}