#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;

	deque <int> dq ;
	deque <int> points (M,-1);

	for (int i = 1; i<=N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> points[i];
	}

	for (int i = 0; i < M; i++) {
		//추출해야하는 수의 위치를 현재 덱에서 찾기
		int point = points.front();
		int idx = 0;
		points.pop_front();
		for (int j = 0;j<dq.size(); j++) {
			if (point == dq[j]) {
				idx = j;
				break;
			}
		}

		//인덱스가 가운데보다 왼쪽
		if (idx <= dq.size() / 2) {
			for (int j = 0; j < idx; j++) {
				int num = dq.front();
				dq.pop_front();
				dq.push_back(num);
			}
			dq.pop_front();
			cnt += idx;
		}
		//인덱스가 가운데보다 오른쪽
		else {
			for (int j = 0; j < dq.size()-idx; j++) {
				int num = dq.back();
				dq.pop_back();
				dq.push_front(num);
			}
			cnt += dq.size() - idx;
			dq.pop_front();
		}
	
	}

	cout << cnt;
}