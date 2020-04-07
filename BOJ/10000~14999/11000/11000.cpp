#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N;
priority_queue<pair<int, int> > pq;
priority_queue<pair<int, int> > nowClass;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pq.push(make_pair(-a, -b));
    }

    int ans = 0;
    nowClass.push(make_pair(0, 0));
    int nowEndTime = 0;
    for(int i = 0 ; i < N ; i++) {
        // 강의 중인 것들의 끝나는 시간과 새로운 강의의 시작 시간과 비교해서 
        // 새로운 강의가 더 빨리 시작하면 nowClass에 넣고
        // 아니면 그 안에 있는 것들 비교해서 비움
        // nowClass->first 현재 강의의 끝나는 시간
        // pq->first 새로운 강의의 시작시간
        if(-nowClass.top().first <= -pq.top().first) {
            while(1) {
                if(nowClass.empty()) break;
                if(-nowClass.top().first > -pq.top().first) break;
                
                nowClass.pop();
            }
        }
        nowClass.push(make_pair(pq.top().second, pq.top().first));
        pq.pop();

        ans = max(ans, (int)nowClass.size());
    }

    printf("%d\n", ans);
}