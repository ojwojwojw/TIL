# 노드와 간선 형태로 된 dfs
```
#include <iostream>
#include <cstring>
using namespace std;

# define MAX_N 10
int N , E ;
int Graph[MAX_N][MAX_N];
bool Visited[MAX_N];

void dfs(int node) {
	Visited[node] = true;
	cout << node << ' ';

	for (int next = 0; next < N; ++next) {
		if (!Visited[next] && Graph[node][next])
			dfs(next);
	}
}

int main(){
	cin >> N >> E;
	memset(Visited, 0, sizeof(Visited));
	memset(Graph, 0, sizeof(Graph));
	for (int i = 0; i < E;  ++i) {
		int u ,v;
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
	}
	dfs(0);
	return 0;
}
```

# 스택을 이용한 방법
```
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

# define MAX_N 10
int N , E ;
int Graph[MAX_N][MAX_N];

void dfs(int node) {
	bool visited[MAX_N] = { false };

	stack<int> mystack;
	mystack.push(node);

	while (!mystack.empty()) {
		int curr = mystack.top();
		mystack.pop();

		if (visited[curr])continue;
		
		visited[curr] = true;
		cout << curr << ' ';

		for (int next = 0; next < N; ++next) {
			if (!visited[next] && Graph[curr][next])
				mystack.push(next);
		}
	}

}

int main(){
	cin >> N >> E;
	
	memset(Graph, 0, sizeof(Graph));
	for (int i = 0; i < E;  ++i) {
		int u ,v;
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
	}
	dfs(0);
	return 0;
}
```
