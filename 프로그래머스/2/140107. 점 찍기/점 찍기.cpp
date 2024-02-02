#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (int i = 0 ; i <= d; i+=k){
        int limit = ((sqrt(pow(d,2)-pow(i,2)))/k)+1;
        answer += limit;
        //cout<<limit<<endl;
    }
    
    
    return answer;
}