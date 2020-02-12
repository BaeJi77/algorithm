//  https://www.acmicpc.net/problem/15683
//  15683_감시.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 22..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int n,m,map[10][10],temp[10][10],cnt,ans;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<pair<int, pair<int, int>>> vt;


void copyMap(int (*a)[10] , int (*b)[10]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

bool isposs(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}

int bfs(){
    int tempMap[10][10];
    copyMap(tempMap, temp);
    bool visited[10][10] = {0};
    queue<pair<int, int>> qu;
    int count = 0;
    
    qu.push({0,0});
    visited[0][0] = true;
    while (int s = qu.size()) {
        while (s--) {
            int y = qu.front().first;
            int x  =qu.front().second;
            qu.pop();
            
            if(y==0 && x==0) count++;
            
            for (int i = 0; i < 4; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                
                if(isposs(yy, xx) == false) continue;
                if(visited[yy][xx] == true) continue;
                qu.push({yy,xx});
                visited[yy][xx] = true;
            }
        }
    }
    return count;
}

void solve(int y, int x , int visit){
    if(visit == (1<<(cnt+1))-1){
        int count = bfs();
        ans = min(ans , count);
        return;
    }
    
    
    
}

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++) {
            scanf("%d" , &map[i][j]);
            if(1 <= map[i][j] && map[i][j] <= 5)
                vt.push_back({map[i][j] , {i,j}});
        }
    }
    
    ans = INT_MAX;
    cnt = vt.size();
    for (int i = 0; i < vt.size(); i++) {
        copyMap(temp, map);
        int visit = vt[i].first;
        int y = vt[i].second.first;
        int x = vt[i].second.second;
        solve(y,x,visit);
    }
    
}
