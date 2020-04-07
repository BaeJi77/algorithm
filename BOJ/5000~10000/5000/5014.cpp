#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int F,S,G,U,D;
bool visited[1000010];

int bfs(int start) {
    int cnt = 0;
    queue<int> qu;
    qu.push(start);
    visited[start] = true;

    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();

            if(now == G)
                return cnt;

            int next = now + U;
            if(next <= F && visited[next] == false) {
                visited[next] = true;
                qu.push(next);
            }

            next = now - D;
            if(next >= 1 && visited[next] == false) {
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
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int ret = bfs(S);
    if(ret == -1) printf("use the stairs");
    else printf("%d", ret);
}