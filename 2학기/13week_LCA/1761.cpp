#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 40000
using namespace std;
int N,Q,par[20][MAX+4],dep[MAX+4];
vector<vector<pair<int,int> > > vt;

void dfs(int cur,int parV){
    for(auto &next : vt[cur]){
        int pos = next.first;
        int cost = next.second;
        if(pos == parV) continue;
        par[0][pos] = cur;
        dep[pos] = dep[cur] + cost;
        dfs(pos,cur);
    }
}

int main(){
    scanf("%d" , &N);
    vt.resize(N+1);
    for(int i = 0 ; i < N-1 ; i++){
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt[a].push_back({b,c});
        vt[b].push_back({a,c});
    }

    dfs(1,0);
}