#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int W[101];
int V[101];
int DP[101][100001];
int ans = 0;
int N, K;

int main() {
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}


	for (int i = 1; i < N + 1; i++) {
		for (int k = 1; k < K + 1; k++) {
			//담을 수 있을때와 없을때
			if (W[i] <= k) {
				DP[i][k] = max(DP[i-1][k - W[i]] + V[i], DP[i-1][k]);
			}
			else {
				DP[i][k] = DP[i-1][k];
			}
		}
	}

	//for (int row = 1; row < N + 1; row++) {
	//	for (int limit = 1; limit < K + 1; limit++) {
	//		cout << DP[row][limit] << ' ';
	//	}
	//	cout << endl;
	//}

	cout << DP[N][K];

	return 0;
}