#include <iostream>
#include <algorithm>
#define MAX 9


using namespace std;

int N, M;
int ans[MAX];
int nums[MAX];
bool visited[MAX] = { false,};

void dfs(int depth) {
	if (depth == M ) {

		for (int i = 0; i<M; i++) {
			cout << ans[i] <<' ';
		}
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < N; i++) {	
		if (!visited[i] && nums[i] != before) {
			before = nums[i];

			ans[depth] = nums[i];
			visited[i] = true;
			dfs(depth + 1);
			visited[i] = false;

		}
	}
}

int main() {
	cin >> N >> M;
	int idx = 0;
	for (int i = 0; i<N; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + N);
	dfs(0);
}