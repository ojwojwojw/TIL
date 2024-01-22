#include <iostream>
#include <vector>;
using namespace std;

#define MAX 9

int N, M;
int arr[MAX] = {0,};
int visited[MAX] = { 0, };

void dfs(int depth,int start) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i<=N; i++) {
		if (!visited[depth]) {
			arr[depth] = i;

			dfs(depth + 1, i);
			
		}
	}
}


int main() {
	cin >> N >> M;
	dfs(0,1);
}