#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cin>>input;
    for(int i = 0 ; i < input.size(); i++) {
        input[i] = toupper(input[i]);
    }
    cout<<input;
}