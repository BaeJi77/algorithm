#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 100000
using namespace std;

int N,Q;
int dep[MAX+4],parent[24][MAX+4];
vector<vector<int> > vt;



void dfs(int cur,int par){
    for(auto &next : vt[cur]){
        if(next == par) continue;
        dep[next] = dep[cur] +1;
        parent[0][next] = cur;
        dfs(next,cur);
    }
}


int lca(int u,int v){
    if(dep[u] > dep[v])
        swap(u,v);
    for(int i = 19 ; i >= 0 ; i--){
        int diff = dep[v] - dep[u];
        if(diff >= (1 << i)) 
            v = parent[i][v];
    }
    if(u == v) return u;
    for(int i = 19 ; i >= 0 ; i--){
        if(parent[i][u] != parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int main(){
    // freopen("input.txt", "r" , stdin);
    scanf("%d" , &N);
    vt.resize(N+1);
    for(int i = 0 ; i < N-1 ; i++){
        int a,b;
        scanf("%d %d" , &a,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    dfs(1,0);
    
    for(int i = 1 ; i <= 20 ; i++){
        for(int j = 1 ; j <= N ; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

    scanf("%d" , &Q);
    for(int i = 0 ; i < Q ; i++){
        int u,v;
        scanf("%d %d" , &u,&v);
        printf("%d\n" , lca(u,v));
    }
}