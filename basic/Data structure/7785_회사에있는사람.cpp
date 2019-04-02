#include <cstdio>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
set<string> st;
set<string>::iterator it;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        string name, query;
        cin>>name>>query;
        if(query == "enter"){
            st.insert(name);
        }else if(query == "leave"){
            st.erase(name);
        }
    }

    vector<string> vt;
    for(it = st.begin() ; it != st.end() ; it++){
        vt.push_back(*it);
    }

    sort(vt.rbegin(), vt.rend());
    for(int i = 0 ; i < vt.size(); i++)
        cout<<vt[i]<<"\n";
}