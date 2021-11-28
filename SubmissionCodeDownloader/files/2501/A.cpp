#include <iostream>
#include <string>

using namespace std;

int main() {
    string S; cin >> S;
    
    for(int i = 0; i < (int)S.size() - 1; ++i) {
        cout << S[i] << "__";
    }
    cout << S[(int)S.size() - 1];

    return 0;

}