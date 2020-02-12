#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int N;
map<string, int> mp;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        string input;
        cin>>input;
        mp[input]++;
    }

    for(int i = 0 ; i < N-1 ; i++){
        string input;
        cin>>input;
        mp[input]++;
    }

    for(auto it = mp.begin(); it != mp.end() ; it++){
        if(it->second % 2 != 0)
            cout<<it->first;
    }
}