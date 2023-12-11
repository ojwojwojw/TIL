# include <iostream>


using namespace std;

int main() {
	int N = 0;
	int array[1000];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}

	long sum = 0;
	long max = 0;

	for (int i = 0; i < N; i++) {
		if (array[i] > max) {
			max = array[i];
		}
		sum += array[i];
	}

	double result = sum * 100.0 / max / N;
	cout << result << "\n";

}