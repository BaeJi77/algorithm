#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
bool visited[300001];
vector<vector<int> > map;
vector<int> ans;

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
    scanf("%d", &N);
    map.resize(N+1);
    // if(N == 2) {
    //     printf("1 2");
    //     return 0;
    // }

    for(int i = 0 ; i < N - 2 ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i = 1 ; i <= N ; ++i) {
        if(visited[i]) continue;
        ans.push_back(i);
        dfs(i);
    }

    for(auto val : ans) 
        printf("%d ", val);
}