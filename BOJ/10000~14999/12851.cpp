#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1e5;

int N, K, cnt;
int k[MAX + 10];
int visited[MAX + 10];

void solve(int start, int end) {
    memset(visited, -1, sizeof(visited));
    int cnt = 0;
    bool isFinished = false;
    queue<int> qu;
    qu.push(start);
    k[start]++;
    visited[start] = 0;
    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();
            
            if(now == end) {
                isFinished = true;
                break;
            }
            
            if(now + 1 <= MAX) {
                if(visited[now + 1] == -1 || visited[now + 1] == cnt) {
                    k[now + 1]++;
                    visited[now + 1] = cnt;
                    qu.push(now+1);
                }
            }
            if(now - 1 >= 0) {
                if(visited[now - 1] == -1 || visited[now - 1] == cnt) {
                    k[now - 1]++;
                    visited[now - 1] = cnt;
                    qu.push(now - 1);
                }
            }
            if(now * 2 <= MAX) {
                if(visited[now * 2] == -1 || visited[now * 2] == cnt) {
                    k[now * 2]++;
                    visited[now * 2] = cnt;
                    qu.push(now * 2);
                }
            }
        }

        if(isFinished)
            break;
        cnt++;
    }
    printf("%d\n%d", cnt, k[end]);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    solve(N, K);
}