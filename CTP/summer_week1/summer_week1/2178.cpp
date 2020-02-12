//
//  2178.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int map[110][110];
int visited[110][110];
int m,n,dist;
string input;
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};

bool isposs(int y,int x){
    return (x>=0) && (y>=0) && (x<m) && (y<n);
}

void bfs(int y,int x){
    queue<pair<int, int>> qu;
    qu.push({y,x});
    while (int s = qu.size()) {
        while (s--) {
            int dy = qu.front().first;
            int dx = qu.front().second;
            
            if (dy == n-1 && dx == m-1) return;
            qu.pop();
            for (int i = 0 ; i < 4; i++) {
                int yy = dy + py[i];
                int xx = dx + px[i];
                if(isposs(yy, xx) == true&& map[yy][xx] == true){
                    map[yy][xx] = 0;
                    qu.push({yy,xx});
                }
            }
        }
        dist++;
    }
}


int main(){
    scanf("%d %d" , &n,&m);
    getchar();
    for (int i = 0 ; i < n; i++) {
        getline(cin,input);
        for (int j = 0 ; j < input.length(); j++) {
            map[i][j] = input[j]-'0';
        }
    }
    bfs(0,0);
    printf("%d" , dist+1);
}

