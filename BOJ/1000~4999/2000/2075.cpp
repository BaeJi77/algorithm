#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
priority_queue<int> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            int k;
            scanf("%d", &k);
            pq.push(-k);
            if(pq.size() > N)
                pq.pop();
        }
    }
    printf("%d", -pq.top());
}