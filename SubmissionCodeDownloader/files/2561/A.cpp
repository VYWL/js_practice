#include<iostream>
#include<string>
using namespace std;

int main(void){

    string s;
    string ts = "";
    cin>>s;

    for(int i=0; i<2*s.length()-1; i++){
        int j = i%2;
        if(j==0){
            ts+=(s[i/2]);
        }
        else ts+=("__");
    }
    cout<<ts;
    return 0;
}
