//  https://www.acmicpc.net/problem/1194
//  1194_달이 차오른다, 가자.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 22..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;

int n,m,sy,sx;
char map[54][54];
bool visited[54][54][1<<7];
queue<pair<int, pair<int, int>>> qu;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

bool isposs(int y,int x){
    return 0<=x&&x<m&&0<=y&&y<n;
}

int bfs(int y,int x){
    int cnt = 0;
    qu.push({0,{y,x}});
    visited[y][x][0] = true;
    while (int s = qu.size()) {
        while (s--) {
            int key = qu.front().first;
            int fy = qu.front().second.first;
            int fx = qu.front().second.second;
            qu.pop();
            
            if(map[fy][fx] == '1') return cnt;
            
            for (int i = 0; i < 4; i++) {
                int nkey = key;
                int yy = fy + dy[i];
                int xx = fx + dx[i];
                
                if(isposs(yy, xx) == false) continue;
                if(map[yy][xx] == '#') continue;
                else if(islower(map[yy][xx])) nkey |= 1<<(map[yy][xx]-'a');
                else if(isupper(map[yy][xx]))
                    if((nkey & (1<<(map[yy][xx]-'A'))) == false) continue;
                
                if(visited[yy][xx][key] == true) continue;
                
                qu.push({nkey,{yy,xx}});
                visited[yy][xx][nkey] = true;
            }
        }
        cnt++;
    }
    
    return -1;
}

int main(){
    scanf("%d %d", &n,&m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            char ch = getchar();
            map[i][j] = ch;
            if(ch == '0'){
                sy = i;
                sx = j;
            }
        }
    }
    
    printf("%d" , bfs(sy,sx));
}
