#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int, pair<int, string> > vip;

int N;
vip vt;
map<int, pair<int, string> > mp;

bool comp(const vip &a, const vip &b){
    
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = N-1; i >= 0 ; i++){
        int year;
        int name;
        cin>>year>>name;
        mp[year] = make_pair(i, name);
    }

    for(auto it = mp.begin() ; it != mp.end(); it++){
        cout<<it->first<<" "<<it->second.second<<"\n";
    }
}