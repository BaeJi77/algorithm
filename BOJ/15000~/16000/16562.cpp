#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M, K;
bool visited[10001];
priority_queue<pair<int, int> > friends;
vector<vector<int> > map;

void dfs(int x) {   
    visited[x] = true;
    for(int i = 0 ; i < map[x].size() ; ++i) {
        int next = map[x][i];
        if(visited[next]) continue;
        dfs(next);
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1 ; i <= N ; ++i) {
        int a; 
        scanf("%d", &a);
        friends.push(make_pair(-a, i));
    }

    map.resize(N+1);
    for(int i = 0 ; i < M ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int totalMoney = 0;
    while(!friends.empty()) {
        int needMoney = -friends.top().first;
        int friendNumber = friends.top().second;

        friends.pop();
        if(visited[friendNumber]) continue;

        totalMoney += needMoney;
        dfs(friendNumber);
    }

    if(K >= totalMoney) printf("%d", totalMoney);
    else printf("Oh no");
}