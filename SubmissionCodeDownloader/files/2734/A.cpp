#include <iostream>
#include <string>

using namespace std;

int main(void){
    string s;
    cin >> s;
    for(int i=0; i<s.length()-1; i++){
        cout << s[i] << "__";
    }
    cout << s[s.length()-1];
}