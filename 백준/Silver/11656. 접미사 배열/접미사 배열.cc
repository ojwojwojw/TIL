#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	vector<string> S;
	string input;
	cin >> input;


	int N = input.length();
	string addedString ="";


	for (int i = 0; i < N; i++) {
		addedString = input[N - 1 - i] + addedString;
		S.push_back(addedString);
	}

	sort(S.begin(), S.end());

	for (string s : S) {
		cout << s << endl;
	}

}