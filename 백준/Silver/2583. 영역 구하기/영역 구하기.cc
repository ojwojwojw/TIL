#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1, 0,-1 };
int M, N, K;
vector<int> answer;

void bfs(vector < vector<int>>&G,int ci, int cj) {
	vector < vector<int> >Q;
	int cnt = 0;
	Q.push_back({ ci,cj });
	G[ci][cj] = 1;
	while (!Q.empty()) {
		ci = Q.front()[0];
		cj = Q.front()[1];
		cnt++;
		Q.erase(Q.begin());
		for (int d = 0; d < 4; d++) {
			int ni = ci + dx[d];
			int nj = cj + dy[d];
			if (0 <= ni && ni < M && 0 <= nj && nj < N && !G[ni][nj]) {
				Q.push_back({ ni,nj });
				G[ni][nj] = 1;
			}
		}
	}
	answer.push_back(cnt);
}

int main() {

	cin >> M >> N >> K;
	vector < vector<int>> G (M, vector<int>(N, 0));


	//직사각형 정보를 2차원 배열에 입력
	for (int k = 0; k<K; k++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int i = y1; i < y2; i++) {
				G[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!G[i][j]) {
				bfs(G,i,j);
			}
		}
	}
	

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int num : answer) {
		cout << num << ' ';
	}


}