#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size() - 1; ++i)
	{
		cout << s[i] << "__";
	}
	cout << s[s.size() - 1];


	return 0;
}