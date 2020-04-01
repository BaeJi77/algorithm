#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1e5;

int N, K, cnt;
int visited[MAX + 10];

void solve(int start, int end) {
    memset(visited, -1, sizeof(visited));
    int ret = MAX + 10;
    
    queue<pair<int, int> > qu;
    qu.push(make_pair(start, 0));
    visited[start] = 0;
    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front().first;
            int depth = qu.front().second;
            qu.pop();
            
            if(now == end) {
                ret = min(ret, depth);
            }
            
            if(now + 1 <= MAX) {
                if(visited[now + 1] == -1 || visited[now + 1] > depth) {
                    visited[now + 1] = depth + 1;
                    qu.push(make_pair(now+1, depth + 1));
                }
            }
            if(now - 1 >= 0) {
                if(visited[now - 1] == -1 || visited[now - 1] > depth) {
                    visited[now - 1] = depth + 1;
                    qu.push(make_pair(now - 1, depth + 1));
                }
            }
            if(now * 2 <= MAX) {
                if(visited[now * 2] == -1 || visited[now * 2] > depth) {
                    visited[now * 2] = depth;
                    qu.push(make_pair(now * 2, depth));
                }
            }
        }
    }

    printf("%d", ret);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    solve(N, K);
}