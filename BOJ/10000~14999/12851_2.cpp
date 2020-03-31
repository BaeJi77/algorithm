#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1e5;

int N, K, cnt;
int k[MAX + 10];
bool visited[MAX + 10];

void solve(int start, int end) {
    int cnt = 0;
    bool isFinished = false;
    queue<int> qu;
    qu.push(start);
    visited[start] = true;
    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();
            
            visited[now] = true;
            if(now == end) {
                isFinished = true;
                k[cnt]++;
            }
            
            if(now + 1 <= MAX) {
                if(visited[now + 1] == 0) {
                    qu.push(now+1);
                }
            }
            if(now - 1 >= 0) {
                if(visited[now - 1] == 0) {
                    qu.push(now - 1);
                }
            }
            if(now * 2 <= MAX) {
                if(visited[now * 2] == 0) {
                    qu.push(now * 2);
                }
            }
        }

        if(isFinished)
            break;
        cnt++;
    }
    printf("%d\n%d", cnt, k[cnt]);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    solve(N, K);
}