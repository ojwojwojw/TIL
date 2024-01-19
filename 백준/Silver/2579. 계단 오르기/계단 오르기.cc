#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int points[301]; // 점수 기록
int DP[301];
int N = 0;


int main() {
		
	cin >> N;
	for (int i = 1; i<N+1; i++) {
		cin >> points[i];
	}

	DP[1] = points[1];
	DP[2] = points[2]+points[1];
	for (int i = 3; i < N + 1; i++) {
		DP[i] = max(DP[i - 2] + points[i], DP[i - 3] + points[i - 1] + points[i]);
	}

	cout << DP[N];
	return 0;
}