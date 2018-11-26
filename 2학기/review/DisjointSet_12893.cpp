//  https://www.acmicpc.net/problem/12893
//  DisjointSet_12893.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 2000
using namespace std;

int N,M,color[MAX+4];
vector<vector<int>> vt;
queue<pair<int, int>> qu;

void bfs(int x){
    qu.push({x,1});
    while (int s = qu.size()) {
        while (s--) {
            int here = qu.front().first;
            int col = qu.front().second;
            qu.pop();
            
            if(color[here] != 0)
                continue;
            color[here] = col;
            
            for (int i = 0; i < vt[here].size(); i++) {
                int there = vt[here][i];
                if(color[there] == 0)
                    qu.push({there,3-col});
            }
        }
    }
}


int main(){
    scanf("%d %d", &N,&M);
    vt.resize(N+1);
    for (int i = 0; i <M; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        if(color[i] == 0)
            bfs(i);
    }
    
    bool result = false;
    for (int i = 1; i <= N ; i++) {
        for (int j = 0; j < vt[i].size(); j++) {
            int here = vt[i][j];
            if(color[i] == color[here])
                result = true;
        }
    }
    
    if(result) printf("0");
    else printf("1");
}
