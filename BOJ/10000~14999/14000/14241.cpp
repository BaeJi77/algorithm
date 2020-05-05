#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, ans;
priority_queue<int> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        int k;
        scanf("%d", &k);
        pq.push(-k);
    }

    while(pq.size() != 1) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        
        int temp = a + b;

        ans += a * b;
        pq.push(-temp);
    }

    printf("%d", ans);
}