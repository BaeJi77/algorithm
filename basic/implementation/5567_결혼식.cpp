#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<vector <int > > vt;
bool visited[504];
int cnt;

void dfs(int here, int depth){
    if(depth > 2)
        return;
    if(here != 1)  
        cnt++;
    visited[here] = true;
    
    for(auto there : vt[here]){
        if(!visited[there])
            dfs(there, depth + 1);
    }
}

void bfs(int here){
    int depth = 0;
    queue<int> qu;
    visited[here] = true;
    qu.push(here);
    while(int s = qu.size()){
        if(depth > 2)
            break;
        // cnt += qu.size();
        while(s--){
            int now = qu.front();
            qu.pop();
            if(depth != 0)
                cnt++;

            for(auto there : vt[now]){
                if(visited[there] == false){
                    qu.push(there);
                    visited[there] = true;
                }
            }
        }
        depth++;
    }
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    vt.resize(N+1);
    for(int i = 0 ; i < M ; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    // dfs(1, 0);
    bfs(1);
    printf("%d", cnt);
}