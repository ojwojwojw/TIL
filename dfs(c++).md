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

# fulid fill 예제

```
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


# define MAX_N 5
struct Point {
	int row, col;
};
int D[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, Arr[MAX_N][MAX_N];


void dfs(int r , int c , int color) {
	bool visited[MAX_N][MAX_N] = { false };
	stack<Point> mystack;
	mystack.push({ r,c });

	while (!mystack.empty()) {
		Point curr = mystack.top();
		mystack.pop();
		
		if (visited[curr.row][curr.col]) continue;

		visited[curr.row][curr.col] = true;
		Arr[curr.row][curr.col] = color;

		for (int i = 0; i < 4; ++i) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr<0 || nr>N - 1 || nc<0 || nc>N - 1) continue;
			if (visited[nr][nc]) continue;
			if (Arr[nr][nc] == 1) continue;
			mystack.push({ nr,nc });
		}
	}

}

int main(){
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> Arr[i][j];
	int sr, sc, color;
	cin >> sr >> sc >> color;
	dfs(sr, sc, color);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << Arr[i][j];
		}
		cout << endl;
	}
	return 0;
}
```
