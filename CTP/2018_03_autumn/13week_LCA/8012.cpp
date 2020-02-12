#include <cstdio>
#include <vector>

#define MAX 30000
using namespace std;

int N,Q,dep[MAX+4],par[20][MAX+4];
vector<vector<int> > vt;


void dfs(int cur,int parV){
    for(auto &next : vt[cur]){
        if(next == parV) continue;
        dep[next] = dep[cur] +1;
        par[0][next] = cur;
        dfs(next,cur);
    }
}

int lca(int u,int v){
    if(dep[u] > dep[v]) swap(u,v);
    for(int i = 16 ; i >= 0 ; i--){
        int diff = dep[v] - dep[u];
        if(diff >= (1<<i))
            v = par[i][v];
    }

    if(u==v)
        return dep[u];

    for(int i = 16 ; i >=0 ;i--){
        if(par[i][u] != par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return dep[par[0][u]];
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    vt.resize(N+1);
    for(int i = 0; i < N-1 ; i++){
        int a,b;
        scanf("%d %d" , &a,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

    dfs(1,0);
    for(int i = 1 ; i <= 16 ; i++){
        for(int j = 1 ; j <= N ; j++){
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    
    int result=0;
    int u = 1;
    scanf("%d" , &Q);
    for(int i = 0 ; i < Q ; i++){
        int v,dist;
        scanf("%d" , &v);
        dist = dep[u] + dep[v] - 2*lca(u,v);
        // printf("%d %d %d %d %d\n"  , u,v, dep[u], dep[v] , lca(u,v));
        result += dist;
        u = v;
    }

    printf("%d" , result);
}