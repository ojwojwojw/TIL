#include <iostream>
#include <vector>

using namespace std;

int main() {
	int TC;
	cin >> TC;
	int answer = 0;
	int N;

	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		vector<int> DP(12 ,-1);
		
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;

		for (int i = 4; i < 12; i++) {
			DP[i] = DP[i - 1] + DP[i - 2]  + DP[i - 3];
		}

		cout << DP[N] <<'\n';
	}

	return 0;
}