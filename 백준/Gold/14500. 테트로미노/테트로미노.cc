#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int maxV = -1;
	int temp = 0;

	vector<vector<int>> originalGrid(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0 ; j < M; j++) {
			cin >> originalGrid[i][j];
		}

	}


	//2차원 배열을 상하 대칭해서 계산을 쉽게 한다
	vector<vector<int>> Grid(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Grid[N-1-i][j] = originalGrid[i][j];
		}
	}


	// 막대기 모양 탐색
	// 가로막대기
	for (int i = 0; i < M - 3; i++) {
		for (int j = 0; j < N; j++) {
			temp = Grid[j][i] + Grid[j][i + 1] + Grid[j][i + 2] + Grid[j][i + 3];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "가로막대기:" << temp << endl;
		}
	}

	// 세로막대기
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N-3; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[2+j][i] + Grid[3+j][i];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "세로막대기:" << temp << endl;
		}
	}

	// 네모 모양 탐색
	for (int i = 0; i < M-1; i++) {
		for (int j = 0; j < N-1; j++) {
			temp = Grid[0+j][i] + Grid[0+j][i + 1] + Grid[1+j][i] + Grid[1+j][i + 1];
			if (temp > maxV) {
				maxV = temp;
			}
		}
		//cout << "네모:" << temp << endl;
	}

	// L 모양 탐색 
	// 1형태 (바닥에 한칸 닿고 세로로 세칸)
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N-2; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[2+j][i] + Grid[2+j][i + 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 1형태:" << temp << endl;
		}
	}

	// 2형태 (1의 좌우반전)
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[2+j][i] + Grid[2+j][i - 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 2형태:" << temp << endl;
		}
	}

	// 3형태 (바닥에 한칸 닿고 세로로 두칸)
	for (int i = 0; i < M - 2; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[1+j][i + 1] + Grid[1+j][i + 2];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 3형태:" << temp << endl;
		}
	}

	// 4형태 (3의 좌우반전)
	for (int i = 2; i < M; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[1+j][i - 1] + Grid[1+j][i - 2];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 4형태:" << temp << endl;
		}
	}

	// 5형태 (바닥에 두칸 닿음)
	for (int i = 0; i < M-1; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[0+j][i] + Grid[0+j][i + 1] + Grid[1+j][i] + Grid[2+j][i];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 5형태:" << temp << endl;
		}
	}

	// 6형태 (5의 좌우반전)
	for (int i = 1; i < M-1; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[0+j][i] + Grid[0+j][i + 1] + Grid[1+j][i + 1] + Grid[2+j][i + 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 6형태:" << temp << endl;
		}
	}


	// 7형태 (바닥에 세칸 닿음)
	for (int i = 0; i < M - 2; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[0+j][i] + Grid[0+j][i + 1] + Grid[0+j][i + 2] + Grid[1+j][i];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 7형태:" << temp << endl;
		}
	}


	// 8형태 (7의 좌우반전)
	for (int i = 0; i < M - 2; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[0+j][i] + Grid[0+j][i + 1] + Grid[0+j][i + 2] + Grid[1+j][i + 2];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "L 8형태:" << temp << endl;
		}
	}


	//번개모양
	//1형태 세워져 있고 벽에 두변이 닿은채로 시작
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[1+j][i + 1] + Grid[2+j][i + 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "번개 1형태:" << temp << endl;
		}
	}

	//2형태(1형태의 좌우반전)
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[0+j][i] + Grid[1+j][i] + Grid[1+j][i - 1] + Grid[2+j][i - 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "번개 2형태:" << temp << endl;
		}
	}

	//3형태 누워져 있고 벽에 아랫쪽 한칸이 닿은채로 시작
	for (int i = 0; i < M - 2; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[j][i] + Grid[j][i + 1] + Grid[1+j][i + 1] + Grid[1+j][i + 2];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "번개 3형태:" << temp << endl;
		}
	}

	//4형태 (3형태의 좌우반전)
	for (int i = 1; i < M-1; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[j][i] + Grid[j][i + 1] + Grid[1+j][i] + Grid[1+j][i - 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "번개 4형태:" << temp << endl;
		}
	}


	// ㅗ 모양
	// 1형태 바닥에 세면이 닿아있음
	for (int i = 1; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[j][i] + Grid[j][i + 1] + Grid[j][i - 1] + Grid[1+j][i];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "ㅗ 1형태:" << temp << endl;
		}
	}

	// 2형태 바닥에 한 면이 닿아있음
	for (int i = 1; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			temp = Grid[j][i] + Grid[1+j][i] + Grid[1+j][i - 1] + Grid[1+j][i + 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "ㅗ 2형태:" << temp << endl;
		}
	}

	// 세로에 3면이 닿은채로 시작
	for (int i = 0; i < M-1; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[j][i] + Grid[1+j][i] + Grid[2+j][i] + Grid[1+j][i + 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "ㅗ 3형태:" << temp << endl;
		}
	}

	// 세로에 한면이 닿은채로 시작
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < N - 2; j++) {
			temp = Grid[j][i] + Grid[1+j][i] + Grid[2+j][i] + Grid[1+j][i - 1];
			if (temp > maxV) {
				maxV = temp;
			}
			//cout << "ㅗ 4형태:" << temp << endl;
		}
	}


	cout << maxV;
}