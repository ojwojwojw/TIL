#include <iostream>
#include <vector>

using namespace std;

int GCD(int a ,int b){
	if (b == 0) {
		return  a;
	}

	return GCD(b, a % b);
}

int main() {
	int N, S;
	cin >> N >> S;
	int minV = 1000000000;
	int input;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		int diff = abs(S - input);
		ans = GCD(diff, ans);
	}
	cout << ans;
	return 0;
}