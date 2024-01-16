#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> G(100001, vector<int>{}); // 인접 리스트
bool visited[100001]; // 방문여부체크
int answer[100001]; // 정답 배열

void dfs(int parent) {
	visited[parent] = true;

	for (int i = 0; i < G[parent].size() ; i++) {
		int child = G[parent][i];
		if (!visited[child]) {	
			answer[child] = parent;
			dfs(child);
		}
	}	
}

int main() {
	cin >> N;

	//인접 리스트
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	// dfs 시작
	dfs(1);

	for (int i = 2; i<N+1; i++) {
		cout << answer[i] << '\n';
	}
}