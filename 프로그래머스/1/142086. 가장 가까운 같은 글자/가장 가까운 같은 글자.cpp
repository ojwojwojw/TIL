#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    // DAT 선언 및 모든 요소를 -1로 초기화
    vector<int> DAT(256, -1);
    
    //문자열을 한 글자씩 순회한다
    for (int i ; i < s.size(); i++){
        //DAT의 정보를 조회해서 최근 발견된 인덱스가 어디인지 판단후 answer에 숫자를 push해준다
        if(DAT[s[i]] == -1 ){
            answer.push_back(-1);
        }else{
            answer.push_back(i - DAT[s[i]]);
        }
        //해당 글자가 최근에 몇번 인덱스에서 발견되었는지를 DAT에 저장한다
        DAT[s[i]] = i;
    }
    
    //debug
    //cout<< 'DAT:' << endl;
    //for (int i =0 ; i<256; i++){
    //    cout << DAT[i] << " ";
    //}
    //cout << endl;
    

    return answer;
}