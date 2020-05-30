#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);

    int N, M;
    scanf("%d %d", &N, &M);
    
    priority_queue<int> pq;
    for(int i = 0 ; i < N ; i++) {
        int a;
        scanf("%d", &a);
        pq.push(-a);
    }

    for(int i = 0 ; i < M ; i++) {
        int a;
        scanf("%d", &a);
        pq.push(-a);
    }

    while(!pq.empty()) {
        printf("%d ", -pq.top());
        pq.pop();
    }
}