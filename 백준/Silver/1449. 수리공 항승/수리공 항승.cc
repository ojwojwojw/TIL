#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int answer = 0;

	int N, L;
	cin >> N >> L;
	vector<int> holes (N,-1);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		holes[i] = x;
	}

	sort(holes.begin(), holes.end());

	
	int start = 1;
	for (int hole : holes) {
		if (start <= hole) {
			answer++;
			start = hole + L;
		}
	}

	cout << answer <<'\n';

	return 0;
}