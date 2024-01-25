#include <string>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
 
//PBT = perfect binary tree
bool isPBT(string S){
    bool is_perfect = true;
    int N = S.length() + 1;
    
    while(N>1){
        if(N%2){
            is_perfect = false;
            break;
        }
        N=N/2;
    }
    return is_perfect;
} 
 
 
//문자열로 표시된 트리구조를 재귀로 탐색하며  
//1인 자식노드가 0인 부모를 갖고 있는 모순이 있는지 없는지 확인한다
void recursion (string tree , char before , vector<int> &answer , int idx){
    //cout<< tree <<endl;
    int n = tree.length()/2;
    char now = tree[n];
    
    if(now == '1' && before == '0'){
        answer[idx] = 0;
        return;
    }
    if(n == 0){
        return;
    }
    
    //recursion
    recursion (tree.substr(0,n), now, answer, idx); //left child
    recursion (tree.substr(n+1,2*n), now, answer, idx); //right child
}
 
vector<int> solution(vector<long long> numbers) {
    int N = numbers.size();
    vector<int> answer(N,1);
 
    for(int i = 0 ; i < N; i++){
        //2진수 문자열로 변환
        string binary ="";
        long long number = numbers[i];
        while(number>0){
            char bin_char;
            bin_char = (number%2) + '0';
            binary = bin_char + binary;
            number = number/2;
        }
        
        
        int l = binary.length(); //노드의 개수
        int h = log2(l) + 1; //노드 개수에 l개일때 포화 이진트리의 최소 높이는 log_2(l)
        
        //좌측에 0을 추가해서 포화 이진트리의 길이(2^n-1)만큼 맞춰준다
        if(isPBT(binary)){
            recursion(binary,'1',answer,i);  
        }else{
            while(!isPBT(binary)){
                binary = '0' + binary;   
            }
        }
        recursion(binary,'1',answer,i);  
    }
    return answer;
}