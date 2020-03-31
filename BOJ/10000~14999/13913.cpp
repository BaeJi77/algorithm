#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 1e5;

int N, K;
int back[MAX + 10];
bool visited[MAX + 10];

void solve(int start, int end) {
    int cnt = 0;
    bool isFinished = false;
    queue<int> qu;
    qu.push(start);
    visited[start] = true;
    back[start] = -1;
    while(int s = qu.size()) {
        while(s--) {
            int now = qu.front();
            qu.pop();
            
            if(now == end) {
                isFinished = true;
                break;
            }
            
            if(now + 1 <= MAX && !visited[now + 1]) {
                back[now + 1] = now;
                visited[now + 1] = true;
                qu.push(now+1);
            }
            if(now - 1 >= 0 && !visited[now - 1]) {
                back[now - 1] = now;
                visited[now - 1] = true;
                qu.push(now - 1);
            }
            if(now * 2 <= MAX && !visited[now * 2]) {
                back[now * 2] = now;
                visited[now * 2] = true;
                qu.push(now * 2);
            }
        }
        if(isFinished)
            break;

        cnt++;
    }

    int backNumber = end;
    stack<int> st;
    while(backNumber != -1) {
        st.push(backNumber);
        backNumber = back[backNumber];
    }

    printf("%d\n", cnt);
    while(!st.empty()) {
        printf("%d ",st.top());
        st.pop();
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    solve(N, K);
}