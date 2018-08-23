//
//  1012.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
//vector<vector<int> > map;
int map[100][100];
int t,m,n,k,cnt; //m:가로 n:세로 map[n][m];
int a,b;
bool visited[100][100];
int dx[4] = { 0 , 0 , 1 , -1};
int dy[4] = { 1 , -1 , 0 , 0};

void dfs(int xx, int yy){
    visited[xx][yy] = true;
    for (int i = 0 ; i < 4 ; i++) {
        int x = dx[i] + xx;
        int y = dy[i] + yy;
        if(x < 0 || y < 0 || x > 50 || y > 50) continue;
        if(visited[x][y] == true) continue;
        if(map[x][y] == false) continue;
        dfs(x, y);
    }
}

int main(){
    scanf("%d" , &t);//test case
    while (t--) {
        cnt=0;
        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));
        scanf("%d %d %d", &m,&n,&k);
        while (k--) {
            scanf("%d %d" , &a , &b);
            map[a][b] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0 ; j < n ; j++) {
                if(visited[i][j] == false && map[i][j] == true) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n" , cnt);
    }
}

