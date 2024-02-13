#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int Arr[5][5];
bool visited[1000000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int i, int j ,int num , int depth) {
	
	if (depth == 6) {
		if (!visited[num]) {
			answer++;
		}

		visited[num] = true;
		return;
	}

	num = 10*num + Arr[i][j];

	for (int d = 0; d < 4; d++) {
		int newI = i + dx[d];
		int newJ = j + dy[d];
		if (0 <= newI && newI < 5 && 0 <= newJ && newJ < 5) {
			dfs(newI, newJ, num, depth + 1);
		}
	}
}


int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j , 0, 0);
		}
	}
	
	cout << answer;

}