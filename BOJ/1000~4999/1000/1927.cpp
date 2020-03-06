#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int x;
        scanf("%d", &x);
        if(x) pq.push(-x);
        else {
            if(pq.empty()) printf("0\n");
            else {
                printf("%d\n", -pq.top());
                pq.pop();
            }
        }
    }
}