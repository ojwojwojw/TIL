#include <iostream>
using namespace std;

int N, K; //물건의 수와 준서가 버틸 수 있는 무게
int W[101];
int V[101];
int DP[100001]; // 1차원 배열도 가능하다.

int main() {
	cin >> N >> K;
	for (int i = 1; i < N + 1; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = K; j >= 0; j--) {
			if (W[i] <= j) {
				DP[j] = max(DP[j], DP[j - W[i]] + V[i]);
			}
		}
	}

	cout << DP[K];

}