#include<iostream>
#include<string>

using namespace std;

int main(){
    string a;
    cin >> a;
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
    {
        cout << "__" << a[i];
    }
    cout << endl;
    
}