//  https://www.acmicpc.net/problem/1987
//  1987.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 7. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int map[30][30];
int n,m,bit,ans;
queue <pair<int, int>> qu;
bool visited[30];
string input;
int X[] = {1,-1,0,0};
int Y[] = {0,0,1,-1};

bool isposs(int y,int x){
    return (x>=0) && (y>=0) && (x<m) && (y<n);
}

void dfs(int y,int x,int cnt){
    visited[map[y][x]] = true;
    for (int i = 0 ; i < 4; i++) {
        int dy = y + Y[i];
        int dx = x + X[i];
        int next = map[dy][dx];
        if(isposs(dy, dx) == false) continue;
        if(visited[next] == true) continue;
        dfs(dy,dx,cnt+1);
    }
    
    visited[map[y][x]] = false;
    ans = max(ans,cnt);
}

int main(){
    scanf("%d %d", &n,&m);
    getchar();
    for (int i=0; i<n; i++) {
        getline(cin, input);
        for (int j = 0 ; j < m; j++) {
            map[i][j] = input[j]-'A';
        }
    }
    
    dfs(0,0,1);
    printf("%d\n" ,ans);
}

