#include <string>
#include <vector>

using namespace std;

// 숫자를 입력하면 좌표를 매핑 해주는 함수
vector<int> Mapp (int num){
    // 좌표 0,0을 1이라 생각한다
    vector <int> ans(2,-1);
    switch(num){
        case 1:
            ans = {0,0};
            break;
        case 2:
            ans = {0,1};
            break;
        case 3:
            ans = {0,2};
            break;
        case 4:
            ans = {1,0};
            break;
        case 5:
            ans = {1,1};
            break;
        case 6: 
            ans = {1,2};
            break;
        case 7:
            ans = {2,0};
            break;
        case 8: 
            ans = {2,1};
            break;
        case 9:
            ans = {2,2};
            break;
        case 0:
            ans = {3,1};
            break;
    }
    return ans;
}

// 좌표를 나타내는 벡터 두개를 입력하면 거리를 리턴하는 함수
int Dist(vector<int> A, vector<int> B){
    return abs(A[0]-B[0])+abs(A[1]-B[1]);
}


string solution(vector<int> numbers, string hand) {
    string result = "";
    int now = 0;
    vector<int> left = {3,0}; // * 좌표로 초기화
    vector<int> right = {3,2}; // # 좌표로 초기화
    
    for (int i = 0 ;i<numbers.size();i++){
        now = numbers[i];
        //무조건 왼손을 쓰는 경우
        if(now == 1 || now == 4 || now == 7 )
        {
            result += 'L';
            left = Mapp(now);
        }
        //무조건 오른손을 쓰는 경우
        else if (now == 3 || now == 6 || now == 9){
            result += 'R';
            right = Mapp(now);
        }
        //먼저 거리를 따져주고, 거리가 같다면 어느손잡이 인지 따지는 경우
        else{
            // 왼손이 더 가까운 경우
            if (Dist(Mapp(now), left) < Dist(Mapp(now), right)){
                result += 'L';
                left = Mapp(now);
            }
            // 오른손이 더 가까운 경우
            else if (Dist(Mapp(now), left) > Dist(Mapp(now), right)){
                result += 'R';
                right = Mapp(now);
            }
            // 거리가 같은 경우
            else{
                if(hand == "right"){
                    result += 'R';
                    right = Mapp(now);
                }
                else if(hand == "left"){
                    result += 'L';
                    left = Mapp(now);
                }
            }            
        }      
    }
    return result;
}