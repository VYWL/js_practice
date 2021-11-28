#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
using namespace std;

int a[3][1001][1001];

set<char> charc[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < 3; i++) {
		for (int row = 1; row <= n; row++)
		{
			for (int col = 1; col <= n; col++) {
				int num; cin >> num;
				a[i][row][col] = num;
			}
		}
	}

	for (int z = 0; z < 3; z++) {
		for (int x = 0; x < 3; x++) {
			if (z == x) continue;
			for (int y = 0; y < 3; y++) {
				if (x == y || x == z || y == z) continue;

				bool correct = true;

				for (int left = 1; left <= n; left++) {
					for (int right = 1; right <= n; right++) {
						int num = 0;
						for (int i = 1; i <= n; i++) {
							num += a[x][left][i] * a[y][i][right];
						}
						if (a[z][left][right] != num)
						{
							correct = false;
							break;
						}
					}
					if (correct == false) break;
				}
				if (correct == false) continue;
				else {
					charc[x].insert('x');
					charc[y].insert('y');
					charc[z].insert('z');
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << 1 * charc[i].count('x') + 2 * charc[i].count('y') + 4 * charc[i].count('z') << endl;
	}

	return 0;
}
