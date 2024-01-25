#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


//문자열로 표시된 트리구조를 dfs로 탐색하며 모순을 검사
bool dfs (string tree){
    //cout<<tree<<endl;
    int l = tree.length();
    char now = tree[l/2];
    string left = tree.substr(0, l/2);
    string right = tree.substr(l/2 + 1, l/2);
    if(l == 1){
        return true;
    }
    else if(now == '0'){
        if (left[l/4] == '1' || right[l/4] == '1'){
            return false;     
        }
    }
        
    return dfs(left) && dfs(right);    
    
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long number : numbers){
        string binary = "";
        
        //number를 2진수 문자열로 변환
        while(number >0){
            char bit = (number & 1) + '0';
            binary = bit + binary;
            number >>= 1;
        }
        
        int l = binary.length(); //노드의 개수
        int h = log2(l) + 1; //노드 개수에 l개일때 포화 이진트리의 최소 높이는 log_2(l)
        
        //이진수 좌측에 0을 추가해서 포화 이진트리의 노드 개수(2^h-1)만큼 맞춰준다
        while(binary.length() < pow(2,h)-1){
            binary = '0' + binary;
        }
        //cout <<binary <<endl;
        
        answer.push_back(dfs(binary));
    }
    return answer;
}