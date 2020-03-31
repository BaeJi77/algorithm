#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1e5;

int N, K;
bool visited[100010];

int solve(int start, int end) {
    int cnt = 0;
    queue<int> qu;
    qu.push(start);
    visited[start] = true;
    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();
            
            if(now == end)
                return cnt;
            
            if(now + 1 <= MAX && !visited[now + 1]) {
                visited[now + 1] = true;
                qu.push(now+1);
            }
            if(now - 1 >= 0 && !visited[now - 1]) {
                visited[now - 1] = true;
                qu.push(now - 1);
            }
            if(now * 2 <= MAX && !visited[now * 2]) {
                visited[now * 2] = true;
                qu.push(now * 2);
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    printf("%d", solve(N, K));
}