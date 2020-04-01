#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)  {
        int k;
        scanf("%d", &k);
        pq.push(-k);
    }

    int ans = 0;
    for(int i = 0 ; i < N ; i++) {
        ans += (N - i) * pq.top() * (-1);
        pq.pop();
    }

    printf("%d", ans);
}