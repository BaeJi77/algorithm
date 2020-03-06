#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

string str;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    cin>>str;
    cout<<"..";
    for(int i = 1 ; i <= str.size(); i++) {
        if(i % 3 == 0) cout<<"*";
        else cout<<"#";
        if(i != str.size()) cout<<"...";
        else cout<<"..";
    }
    cout<<"\n";

    for(int i = 1 ; i <= str.size() ; i++) {
        if(i % 3 == 0) cout<<".*.*";
        else cout<<".#.#";

        if(i == str.size()) cout<<".";
    }
    cout<<"\n";

    for(int i = 1 ; i <= str.size() ; i++) {
        if(i % 3 == 0) cout<<"*."<<str[i-1]<<".";
        else {
            if(i % 3 == 1 && i > 3) cout<<"*."<<str[i-1]<<".";
            else  cout<<"#."<<str[i-1]<<".";
        }
        

        if(i == str.size()) {
            if(i % 3 == 0) cout<<"*";
        else cout<<"#";
        }
    }
    cout<<"\n";
    for(int i = 1 ; i <= str.size() ; i++) {
        if(i % 3 == 0) cout<<".*.*";
        else cout<<".#.#";

        if(i == str.size()) cout<<".";
    }
    cout<<"\n";

    cout<<"..";
    for(int i = 1 ; i <= str.size(); i++) {
        if(i % 3 == 0) cout<<"*";
        else cout<<"#";
        if(i != str.size()) cout<<"...";
        else cout<<"..";
    }
    cout<<"\n";
}