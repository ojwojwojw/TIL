#include <iostream>
#include <string>

using namespace std;

# define MAX 8

int cnt = 0; // 몇번째 수열(수) 인지 기록할 변수
int arr[10]; //수열을 기록할
int answer [1000001][10]; //재귀로 구한 데이터를 넣을 곳
bool used[10]; //해당 숫자를 사용했는지 기록(visited와 유사)

bool zeroUsed() {
    for (int i = 0; i < 10; i++) {
        if (i && used[i]) {
            return true;
        }
    }
    return false;
}


void initialize() {
    cnt = 0;
    fill(begin(arr), end(arr), 0);
    fill(begin(used), end(used), false);
}

void dfs(int m ) {
    if (cnt == 1000001) {
        return;
    }

    if (m == MAX) {
        for (int i = 0; i < MAX; i++) {
            answer[cnt][i] = arr[i];
        }
        cnt++;
        return;
    }

    for (int i = 0; i < 10; i++) {
        //used를 검사해서  visited에서 0 이외에 다른것을 썼는지 검사한다
        bool isNonZeroUsed = zeroUsed();
        
        // 001 002 는 되는데 400은 안되게 used를 변형시킨다.
        if (!isNonZeroUsed) {
            used[0] = false;
        }

        if (!used[i]) { 
            used[i] = true;

            //used를 또 검사해서  used에서 0 이외에 다른것을 썼는지 검사한다
            isNonZeroUsed = zeroUsed();
            

            //0이외의 것이 쓰이기전의 0과 이후의 0을 구별하자.
            if (!isNonZeroUsed) {
                arr[m] = -1;
            }
            else {
                arr[m] = i;
            }

            dfs(m + 1);
            used[i] = false;
        }
    }
}


// 메인 함수
int main() {
    int input;
    dfs(0);
    while (true) {
        // 숫자 입력
        cin >> input;

        // 입력된 숫자가 0이면 반복 종료
        if (input == 0) {
            break;
        }
        else {
            // 변수 및 배열 초기화 함수
            initialize();
            // 조건을 만족하는 수를 찾아서 출력
            for (int i = 0; i < MAX; i++) {
                if (answer[input][i] != -1) {
                    cout << answer[input][i];
                }
            }
            cout << '\n';
        }

    }
}
