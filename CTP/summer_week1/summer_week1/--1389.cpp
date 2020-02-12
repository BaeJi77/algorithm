//
//  1389.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 2..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int n,m;
int a,b;
int cnt , totalcnt;
vector <vector <int> > map;
vector<int> result;
bool visited[110];

void dfs(int here){
    visited[here] = true;
    cnt++;
    for (int i = 0; i < map[here].size(); i++) {
        int there = map[here][i];
        if(visited[there] == false) dfs()
    }
}


int main(){
    scanf("%d %d" , &n, &m);
    map.resize(n+1);
    while (m--) {
        scanf("%d %d" , &a ,&b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            int here = map[i][j];
            if(visited[here] == false) dfs(here);
            totalcnt += cnt;
            cnt=0;
        }
        result.push_back(totalcnt);
        totalcnt = 0;
    }
}

