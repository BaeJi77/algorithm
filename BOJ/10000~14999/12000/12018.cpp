#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
priority_queue<int> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N ,&M);
    for(int i = 0 ; i < N ; i++) {
        int a,b;
        scanf("%d %d",&a, &b);
        vector<int> vt;
        for(int j = 0 ; j < a; j++) {
            int k;
            scanf("%d", &k);
            vt.push_back(k);
        }
        sort(vt.begin(), vt.end());
        if(a - b < 0) pq.push(-1);
        else pq.push(-vt[a-b]);
    }

    int size = pq.size();
    int ans = 0;
    for(int i = 0 ; i < size ; i++) {
        int topValue = -pq.top();
        if(M - topValue < 0) break;
        else {
            ans++;
            M -= topValue;
        }
        pq.pop();
    }
    printf("%d", ans);
}