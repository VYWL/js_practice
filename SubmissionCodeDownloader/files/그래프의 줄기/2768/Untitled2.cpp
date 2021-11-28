#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	int cnt[N] = {0};
	
	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		
		cnt[a]++;
		cnt[b]++;
	}
	
	vector<int> result;
	
	for(int i = 0; i < N; ++i) {
		if(cnt[i] > 1) {
			result.push_back(i);
		}
	}
	
	for(auto it = result.begin(); it < result.end(); ++it) {
		cout << *it << ' ';
	}
	
	cout << endl;
	return 0;
}

