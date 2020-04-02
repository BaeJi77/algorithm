#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int, int> > pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        if(k == 0) {
            if(pq.empty()) printf("0\n");
            else {
                printf("%d\n", -pq.top().second);
                pq.pop();
            }
        } else {
            int kk = k > 0 ? -k : k;
            pq.push(make_pair(kk, -k));
        }
        
    }
}