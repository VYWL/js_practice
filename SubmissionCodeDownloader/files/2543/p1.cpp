#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, temp;

	cin >> s;
	for (int i = 0; i < s.size()*3; i++)
	{
		temp += "_";
	}
	
	for (int i = 0; i < s.size(); i++)
	{
		temp[i * 3] = s[i];
	}
	temp.resize(temp.size() - 2);

	cout << temp;
}