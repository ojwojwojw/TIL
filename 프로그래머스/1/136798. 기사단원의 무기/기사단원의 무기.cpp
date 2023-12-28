#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countMeasure(int n, int l ,int p){
    int res = 0;
    
   
    for (int i = 1 ; i*i <= n ;i++){
        if (i*i == n){
            res += 1;
        }
        else if(n%i == 0){
            res += 2;
        }
    }
    
    
    if (n == 1){
        res = 1;
    }
    
    if (res > l){
        res = p;
    }
    
    return res;
}


int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1 ; i<=number; i++){
        //cout << countMeasure(i,limit,power) << endl;
        answer += countMeasure(i,limit,power);
    }

    return answer;
}