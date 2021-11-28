#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int board[1025][1025];

int get_vote(int size, int left, int up) {

	vector<int> v;

	if (size > 2) {
		v.push_back(get_vote(size / 2, left, up));
		v.push_back(get_vote(size / 2, left + size / 2, up));
		v.push_back(get_vote(size / 2, left + size / 2, up + size / 2));
		v.push_back(get_vote(size / 2, left, up + size / 2));
		sort(v.begin(), v.end());
		return v[1];
	}
	if (size == 2) {
		v.push_back(board[left][up]);
		v.push_back(board[left + 1][up]);
		v.push_back(board[left + 1][up + 1]);
		v.push_back(board[left][up + 1]);
		sort(v.begin(), v.end());
		return v[1];
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			int num; cin >> num;
			board[row][col] = num;
		}
	}

	if (n == 1) {
		cout << board[0][0];
		return 0;
	}

	int answer = get_vote(n, 0, 0);

	cout << answer;

	return 0;
}
