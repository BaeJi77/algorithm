#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int N;
        scanf("%d", &N);
        priority_queue<pair<int, int> > pq;
        int total = 0;
        for(int i = 0 ; i < N ; ++i) {
            int k;
            scanf("%d", &k);
            pq.push(make_pair(k, i+1));
            total += k;
        }
        bool isNoWinner = false;
        int topVote = pq.top().first;
        int topIdx = pq.top().second;
        pq.pop();
        if(topVote == pq.top().first) isNoWinner = true;

        if(isNoWinner) printf("no winner");
        else {
            if(topVote > total / 2) printf("majority winner %d", topIdx);
            else printf("minority winner %d", topIdx);
        }
        puts("");
    }
}