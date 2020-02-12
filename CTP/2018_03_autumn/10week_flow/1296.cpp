#include <cstdio>
#include <vector>
#include <cstring>


#define MAX 5000
using namespace std;

int N,M,B[MAX+4],ret;
bool visited[104];

vector<vector<int> > vt;

bool dfs(int here){
    visited[here] = true;
    for(int i = 0 ; i < vt[here].size() ; i++){
        int there = vt[here][i];
        if(B[there] == -1 || !visited[B[there]] && dfs(B[there])){
            B[there] = here;
            return true;
        }
    }
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" , &N,&M);
    vt.resize(N+1);
    for(int i = 0 ; i < M; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        vt[a].push_back(b);
    }

    memset(B,-1,sizeof(B));
    for(int i = 1 ; i <= N ; i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i))
            ret++;
    }

    printf("%d" ,ret);
}