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

int N;
vector<vector<int> > map;
vector<int> rmap;
bool visited[100001];

void dfs(int x, int par) {
    visited[x] = true;
    rmap[x] = par;
    for(int i = 0 ; i < map[x].size() ; ++i) {
        int next = map[x][i];
        if(visited[next]) continue;
        dfs(next, x);
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    map.resize(N+1);
    rmap.resize(N+1);
    for(int i = 0 ; i < N - 1 ; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // 부모를 구하는 로직이 필요함.
    dfs(1, 0);

    stack<int> st;
    for(int i = 0 ; i < N ; ++i) {
        int k;
        scanf("%d", &k);
        st.push(k);
    }

    stack<int> rst;
    for(int i = 0 ; i < N - 1 ; ++i) {
        int child = st.top();
        st.pop();
        int par = st.top();
        if(rmap[child] != par) rst.push(child);
        else {
            while(!rst.empty() && par == rmap[rst.top()]) 
                rst.pop();
        }
    }

    if(rst.empty()) printf("1");
    else printf("0");
}