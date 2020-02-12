#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int k;
set<int> st;


int main(){
    freopen("input.txt","r",stdin);
    vector<int> vt;
    while(scanf("%1d", &k) != EOF){
        vt.push_back(k);
    }

    
    // for(auto it = st.begin(); it != st.end(); it++){
    //     vt.push_back(*it);
    // }

    sort(vt.rbegin(), vt.rend());
    for(int i = 0 ; i < vt.size(); i++)
        printf("%d", vt[i]);
}
