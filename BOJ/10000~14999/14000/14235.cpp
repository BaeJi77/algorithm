#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N;
priority_queue<int> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int a;
        scanf("%d", &a);
        if(a == 0) {
            if(pq.empty()) printf("-1\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        } else {
            for(int j = 0 ; j < a; j++) {
                int k ;
                scanf("%d", &k);
                pq.push(k);
            }
        }
    }
}