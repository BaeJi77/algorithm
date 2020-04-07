#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    priority_queue<int> pq;
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        pq.push(-k);
    }

    int ans = 0;
    for(int i = 0 ; i < N - 1; i++) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        ans += -(first + second);
        pq.push(first + second);
    }

    printf("%d\n", ans);
}