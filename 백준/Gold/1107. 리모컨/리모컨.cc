#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int buttons[10];
bool isAllButtonCrashed = true;


bool canMakeWithButton(string channel) {
	bool result = true;

	for (char ch : channel) {
		if (!buttons[ch - '0']) {
			result = false;
			break;
		}
	}

	return result;
}



int main() {
	fill_n(buttons, 10, 1);

	int ans_up = 0;
	int ans_down = 0;

	int N,M;
	cin >> N >> M;
	
	int idx;
	for (int i = 0; i < M; i++) {
		cin >> idx;
		buttons[idx] = 0;
	}

	for (int i = 0; i < 10; i++) {
		if (buttons[i]) {
			isAllButtonCrashed = false;
		}
	}

	//for (int i = 0; i < 10; i++) {
	//	cout << buttons[i] << " " << endl;
	//}

	if (N == 100) {
		cout << 0;
	}
	else {
		if (isAllButtonCrashed) {
			cout << abs(N - 100);
		}
		else {
			string channel;
			int n = N;
			while (n <= 1000000) {
				channel = to_string(n);
				//cout << channel << endl;
				if (canMakeWithButton(channel)) {
					ans_up += channel.length();
					ans_up += n - N;
					break;
				}

				n++;
			}


			// 이 처리를 안해주면, 위쪽 탐색에서 아무것도 못찾은경우 ans_up이 0이 된다.
			if (n > 1000000) {
				ans_up = abs(N - 100);
			}

			n = N;
			while (n >= 0) {
				
				channel = to_string(n);
				//cout << channel <<endl;
				if (canMakeWithButton(channel)) {
					ans_down += channel.length();
					ans_down += N - n;
					break;
				}

				n--;
			}


			// 이 처리를 안해주면, 아래쪽 탐색에서 아무것도 못찾은경우 ans_up이 0이 된다.
			if (n < 0) {
				ans_down = abs(N - 100);
			}

			//cout << "up: " << ans_up << " " << "down: " << ans_down << endl;
			cout << min(abs(N - 100), min(ans_up, ans_down));

		}
	}
	return 0;
}