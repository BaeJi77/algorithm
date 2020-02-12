#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string> > vt;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        string input;
        cin>>input;
        vt.push_back(make_pair(input.size(), input));
    }

    sort(vt.begin(), vt.end());
    for(int i = 0 ; i < N ; i++){
        if(i != 0 && vt[i].second == vt[i-1].second)
            continue;
        cout<<vt[i].second<<'\n';
    }
}