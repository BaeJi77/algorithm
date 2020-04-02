#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int qy, qx;
bool visited[110];
vector<vector<int> > vt;

int bfs(int start) {
    queue<int> qu;
    int cnt = 0;
    bool isFound = false;

    qu.push(start);
    visited[start] = true;

    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();

            if(now == qx) {
                return cnt;
            }

            for(int i = 0 ; i < vt[now].size(); i++) {
                int next = vt[now][i];
                if(visited[next]) continue;

                visited[next] = true;
                qu.push(next);
            }
        }
        cnt++;
    } 

    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    vt.resize(N+1);
    scanf("%d %d", &qy, &qx);
    scanf("%d", &M);
    for(int i = 0 ; i < M ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

    printf("%d", bfs(qy));
}