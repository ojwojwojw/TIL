#include <iostream>
#include <vector>;
using namespace std;

#define MAX 9

int N, M;
int arr[MAX] = {0,};
bool visited[MAX] = { false, };

void dfs(int depth) {
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i<=N; i++) {
		if (!visited[i]) {
			arr[depth + 1] = i;
			visited[i] = true;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}


int main() {
	cin >> N >> M;
	dfs(0);
}