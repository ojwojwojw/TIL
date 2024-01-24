#include <iostream>
using namespace std;


int N;
int arr[11];
int operators[4]; 	// +,-,x,% 순서
int maxV = -1000000000;
int minV = 1000000000;

void recursion(int depth, int curV) {
	
	if (depth == N) {
		maxV = max(maxV, curV);
		minV = min(minV, curV);
		return ;
	}

	for (int i = 0; i < 4;i++) {
		if (operators[i]) {
			operators[i]--;
			switch (i) {
				case(0):
					recursion(depth + 1, curV + arr[depth]);
					break;
				case(1):
					recursion(depth + 1, curV - arr[depth]);
					break;
				case(2):
					recursion(depth + 1, curV * arr[depth]);
					break;
				case(3):
					recursion(depth + 1, curV / arr[depth]);
					break;
			}
			operators[i]++;
		}
	}
}

int main(void) {

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];
	recursion(1, arr[0]);
	cout << maxV << '\n';
	cout << minV << '\n';

	return 0;
}