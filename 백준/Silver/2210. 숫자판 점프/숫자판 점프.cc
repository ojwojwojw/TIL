#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int Arr[5][5];
bool visited[1000000];

void dfs(int i, int j ,int num , int depth) {
	
	if (depth == 6) {
		if (!visited[num]) {
			answer++;
		}

		visited[num] = true;
		return;
	}

	num = 10*num + Arr[i][j];

	if (0 <= i + 1 && i + 1 < 5 && 0 <= j && j < 5) dfs(i+1, j, num, depth + 1);
	if (0 <= i  && i < 5 && 0 <= j + 1 && j + 1< 5) dfs(i , j+1, num, depth + 1);
	if (0 <= i - 1 && i - 1 < 5 && 0 <= j && j < 5) dfs(i-1, j, num, depth + 1);
	if (0 <= i && i < 5 && 0 <= j - 1 && j - 1 < 5) dfs(i,j-1, num, depth + 1);
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