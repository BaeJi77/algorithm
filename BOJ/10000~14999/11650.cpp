#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int, int> > pq;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        pq.push(make_pair(-x, -y));
    }

    for(int i = 0 ; i < N ; i++) {
        printf("%d %d\n", -pq.top().first, -pq.top().second);
        pq.pop();
    }
}