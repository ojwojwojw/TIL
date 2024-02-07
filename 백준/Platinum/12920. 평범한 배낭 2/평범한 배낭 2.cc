#include <iostream>
using namespace std;

int N, M; //물건의 수와 준서가 버틸 수 있는 무게
int v, c, k; // 입력받는 무게,가치,개수

int DP[100001]; // 1차원 배열

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> v >> c >> k;
		
		int bin = 1;
		while (k > 0) {
			bin = min(bin, k);
			for (int j = M; j >= 0; j--) {
				if (v*bin <= j) {
					DP[j] = max(DP[j], DP[j - v*bin] + c*bin);
				}
			}
			k -= bin;
			bin *= 2;
		}
	}

	cout << DP[M];
}