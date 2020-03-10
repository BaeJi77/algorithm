#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
priority_queue<pair<pair<int, int>, pair<int, int> > > pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    for(int i = 1 ; i <= N ; i++) {
        int k,a,b,c;
        scanf("%d %d %d %d", &k, &a, &b, &c);
        pq.push(make_pair(make_pair(a,b), make_pair(c,k)));
    }

    int ans = 0;
    int contiRankCnt = 1;
    int rank = 1;
    for(int i = 0 ; i < N ; i++) {
        if(pq.top().second.second == K) {
            ans = rank;
            break;
        }
        int nowG = pq.top().first.first;
        int nowS = pq.top().first.second;
        int nowB = pq.top().second.first;
        pq.pop();

        
        int nextG = pq.top().first.first;
        int nextS = pq.top().first.second;
        int nextB = pq.top().second.first;

        if(nextG == nowG && nextS == nowS && nextB == nowB) {
            contiRankCnt++;
            continue;
        }
        rank += contiRankCnt;
        contiRankCnt = 1;
    }

    printf("%d", ans);
}