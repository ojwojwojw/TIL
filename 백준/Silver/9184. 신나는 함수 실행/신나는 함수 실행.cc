#include <iostream>
#include <algorithm>

using namespace std;


// 3차원 배열 DP 선언
int DP[21][21][21];


int w(int a, int b, int c)
{

    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }


    else if (a > 20 || b > 20 || c > 20) {
        return w(20,20,20);
    }

    // 여기가 핵심
    else if (DP[a][b][c]) {
        return DP[a][b][c];
    }
    // 재귀가 발생하지 않게 해야 한다

    else if (a < b && b < c) {
        DP[a][b][c] = w(a,b,c - 1) + w(a,b - 1,c - 1) - w(a,b - 1,c);
        return DP[a][b][c];
    }

    else {
        DP[a][b][c] = w(a - 1,b,c) + w(a - 1,b - 1,c) + w(a - 1,b,c - 1) - w(a - 1,b - 1,c - 1);
        return DP[a][b][c];
    }
 
}


int main() {
    // 입력
    int A = 0;
    int B = 0; 
    int C = 0;
    while (true) {
        cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1) {
            break;
        }
        cout << "w(" << A << ", " << B << ", " << C << ")" << " = " << w(A,B,C)<< "\n";
    }
    
}