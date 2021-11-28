#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1025][1025];
typedef pair<int, int> p;
int two(int a, int b, int c, int d) {
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	sort(v.begin(), v.end());
	return v[1];
}
int bs(int x1, int x2, int y1, int y2, int l) {//l*l
	if (l == 2) {
		return two(arr[x1][y1], arr[x1][y2], arr[x2][y1], arr[x2][y2]);
	}
	int midx = (x1 + x2) / 2;
	int midy = (y1 + y2) / 2;
	return two(bs(x1, midx, y1, midy, l / 2), bs(midx + 1, x2, y1, midy,l/2), bs(x1, midx, midy + 1, y2,l/2), bs(midx + 1, x2, midy + 1, y2,l/2));
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	if (n == 1) {
		cout << arr[1][1];
		return 0;
	}
	else {
		cout<<bs(1, n, 1, n, n);
	}
}