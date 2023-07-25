#include<iostream>
using namespace std;

long long N = 0;
long long answer = 0;


long long fac(long long
	num) {
	if (num == 1 || num == 0) {
		return 1;
	}
	else {
		return num * fac(num - 1);
	}

}

int main(void) {
	cin >> N;
	answer = fac(N);
	cout << answer;

}