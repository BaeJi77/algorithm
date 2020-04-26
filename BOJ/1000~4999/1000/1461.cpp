#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M, plusSum, minusSum;
priority_queue<int> plusPQ;
priority_queue<int> minusPQ;

int calPQ(bool isLast, priority_queue<int> pq) {
    int ret = 0;
    bool first = true;
    while(!pq.empty()) {
        int tempSum = 0;
        int pqSize = pq.size();
        if(first) {
            for(int i = 0 ; i < pqSize % M ; ++i) {
                if(pq.size() == 0) {
                    break;
                }
                if(pq.size() == 1 || i == (pqSize % M) - 1)
                    tempSum = abs(pq.top());
                pq.pop();
            }
            first = false;
        } else {
            for(int i = 0 ; i < M ; ++i) {
                if(pq.size() == 0) {
                    break;
                }
                if(pq.size() == 1 || i == M - 1)
                    tempSum = abs(pq.top());
                pq.pop();
            }
        }
        if(isLast && pq.size() == 0) ret += tempSum;
        else ret += tempSum * 2;
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        if(a > 0) {
            plusPQ.push(-a);
            plusSum += a;
        }
        else {
            minusPQ.push(a);
            minusSum += abs(a);
        }
    }


    int ans = 0;
    ans = min(calPQ(0, minusPQ) + calPQ(1, plusPQ), calPQ(0, plusPQ) + calPQ(1, minusPQ));
    printf("%d", ans);
}