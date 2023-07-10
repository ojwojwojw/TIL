#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(double flo) {
    int answer = 0 ;
    string str = to_string(flo);    
    int pos = str.find('.');
    
    char arr[20];
    strcpy(arr,str.c_str());
    
    for(int i = 0; i < pos ; i++){
        answer = answer * 10 + (arr[i] - '0');
    }
    
    return answer;
}