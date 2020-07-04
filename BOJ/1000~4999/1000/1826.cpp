#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

const int MAX = 987654321;

int N;
vector<pair<int, int>> map;
int des, rest;

priority_queue<pair<int, int>> pq;

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map.push_back({a, b});
    }
    scanf("%d %d", &des, &rest);
    map.push_back({des, 0});

    sort(map.begin(), map.end());

    // 갈 수 있는 최대로 이동함. 거기서 가려는데 가지 못하는 경우
    // 오는 길에 있던 가장 큰 연료를 제공해주는 곳을 더해주고 다음 단계 이동

    int idx = 0;
    int ans = 0;
    while(1) {
        while(map[idx].first <= rest) {
            pq.push({map[idx].second, map[idx].first});
            idx++;
            if(idx == N + 1) break;
        }

        if(idx == N + 1) {
            break;
        }

        // 한번에 가지 못하는 경우가 생김 -> 이전에 있던 주유소 중 가장 많이 기름을 주는 곳 들림
        if(pq.empty()) {
            ans = -1;
            break;
        }
        
        rest += pq.top().first;
        pq.pop();

        ans++;
    }

    printf("%d", ans == -1 ? -1 : ans);
}