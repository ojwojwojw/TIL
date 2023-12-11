# include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int S[100001] = {};
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		S[i] = S[i - 1] + num;
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		int result;
		result = S[b] - S[a-1];
		cout << result << '\n';
	}

	return 0;
}