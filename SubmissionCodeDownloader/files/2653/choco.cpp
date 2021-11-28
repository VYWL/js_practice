#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int row, col, k;
	cin >> row >> col >> k;

	int size = row * col;
	int answer = 0;
	int oldD = abs(row - col);

	while (size > 1) {
		int correct = false;
		size--;
		for (int new_row = 1; size / new_row >= new_row - 1; new_row++) {
			if (size % new_row != 0)
				continue;

			int new_col = size / new_row;
			int newD = abs(new_row - new_col);
			if (abs(newD - oldD) <= k) {
				correct = true;
				answer++;
				break;
			}
		}

		if (correct == false) {
			break;
		}
	}

	cout << answer;
	
	return 0;
}
