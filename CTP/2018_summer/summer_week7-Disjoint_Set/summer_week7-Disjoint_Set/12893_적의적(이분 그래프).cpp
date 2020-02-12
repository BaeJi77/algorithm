//  https://www.acmicpc.net/problem/12893
//  12893_적의적(이분 그래프).cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int color[2004]; // 1 : 빨강 , 2 : 파랑
vector<vector<int>> map;
queue<pair<int, int>> qu;

void bfs(int x){
    qu.push({x,1});
    while (int s = qu.size()) {
        while (s--) {
            int here = qu.front().first;
            int col = qu.front().second;
            qu.pop();
            
            if(color[here] != 0) continue;
            color[here] = col;
            
            for (int i = 0; i < map[here].size(); i++) {
                int there = map[here][i];
                if(color[there] == 0) {
                    qu.push({there, 3-col});
                }
                
            }
        }
    }
}

int main(){
    scanf("%d %d" , &n,&m);
    map.resize(n+1);
    while (m--) {
        int a,b;
        scanf("%d %d" , &a,&b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    for (int i = 1; i <=n; i++) {
        if(color[i] == 0) bfs(i);
    }
    
    bool ans = true;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 0; j < map[i].size(); j++) {
            int here = map[i][j];
            if(color[i] == color[here]){
                ans = false;
            }
        }
    }
    
    if(ans == true) printf("1");
    else printf("0");
}
