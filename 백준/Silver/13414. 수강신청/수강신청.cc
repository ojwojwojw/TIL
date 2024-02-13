#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second <= b.second) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int N, M;
	cin >> N >> M;

	unordered_map <string, int> hash;

	string S;
	for (int i = 0; i < M; i++) {
		cin >> S;
		hash[S] = i;
	}

	vector<pair<string, int>> ordered_hash;

	for (auto student : hash) {
		ordered_hash.push_back(student);
	}

	sort(ordered_hash.begin(), ordered_hash.end(), compare);


	for (int i = 0; i < min(N, (int)ordered_hash.size()) ; i++) {
		cout << ordered_hash[i].first << "\n";
	}


}