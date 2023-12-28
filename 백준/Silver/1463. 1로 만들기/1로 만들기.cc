#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int X;
	cin >> X;

	vector<int> DP(1000001, -1);
	
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	

	for (int i = 4; i < X + 1; i++) {
		int a = 1000000;
		int b = 1000000;
		int c = 1000000;
		
		if (i % 2 == 0) {
			a = DP[i / 2] + 1;
		}
		if (i % 3 == 0) {
			b = DP[i / 3] + 1;
		}
		c = DP[i - 1] + 1;

		DP[i] = min({a, b, c});
		//cout << DP[i] << ' '  ;
	}

	cout << DP[X];
	
}