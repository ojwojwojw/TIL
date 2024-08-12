#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N, vector<int>(M, 0));
	vector<vector<int>> visited(N, vector<int>(M, 0));
	queue<pair<int, int>> Q;
	pair<int, int> v;
	int row, col, nRow, nCol;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> G[i][j];
			if (G[i][j] == 2) {
				v = { i, j };
			}
		}
	}

	Q.push(v);
	while (!Q.empty()) {
		v = Q.front();
		row = v.first;
		col = v.second;
		Q.pop();

		for (int d = 0; d < 4; d++) {
			nRow = row + dx[d];
			nCol = col + dy[d];
			if (0 > nRow || nRow >= N || 0 > nCol || nCol >= M) continue;
			if (visited[nRow][nCol]) continue;
			if (G[nRow][nCol] == 0 || G[nRow][nCol] == 2) continue;
			visited[nRow][nCol] = visited[row][col] + 1;
			Q.push({ nRow,nCol });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && G[i][j] == 1) {
				cout << -1 << " ";
			}
			else {
				cout << visited[i][j] << " ";
			}
	
		}
		cout << endl;
	}

	return 0;
}