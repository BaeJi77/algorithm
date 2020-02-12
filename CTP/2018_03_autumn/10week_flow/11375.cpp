#include <cstdio>
#include <vector>
#include <cstring>

#define MAX 1000
using namespace std;

int N,M,visit[MAX+4],B[MAX+4],ret;
vector<vector<int> > vt;

bool dfs(int here){
    visit[here] = 1;
    
    for(int i = 0 ; i < vt[here].size() ; i++){
        int there = vt[here][i];
        if(B[there] == -1 || !visit[B[there]] && dfs(B[there])){
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
    for(int i = 0 ; i < N ; i++){
        int k;
        scanf("%d" , &k);
        for(int j = 0 ; j < k ; j++){
            int in;
            scanf("%d" , &in);
            vt[i].push_back(in);
        }
    }

    memset(B,-1,sizeof(B));
    for(int i = 0 ; i < N ; i++){
        memset(visit,0,sizeof(visit));
        if(dfs(i))
            ret++;
    }
    printf("%d" , ret);
}