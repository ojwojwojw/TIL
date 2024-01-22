#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int N, M;
int ans[MAX];
int nums[MAX];
int visited[MAX] = { false, };

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i<M; i++) {
			cout << ans[i] <<' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			ans[depth] = nums[i];
			visited[i] = true;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i<N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + N);
	dfs(0);
}