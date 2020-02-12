//
//  14500.cpp
//  11week_second
//
//  Created by Hoon on 2018. 5. 18..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

#define INF 123456789

int n,m,in;
int arr[510][510];
int dx[] = { 1 , -1 , 0 , 0};
int dy[] = { 0 , 0 , 1 , -1};
bool visited[510];
int cnt , sum , MAXX;

void dfs(int x, int y){
    visited[arr[x][y]] = true;
    cnt++;
    if(cnt==4) {
        sum = 0;
        cnt = 0;
        return;
    }
    
    
    for(int i = 0 ; i < 4 ; i++){
        int tx = x + dx[i];
        int ty = y + dx[i];
        
        if(visited[arr[tx][ty]] == true) continue;
        if(tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
        sum += arr[tx][ty];
        dfs(tx,ty);
    }
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d" , &in);
            arr[i][j] = in;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cnt = 0;
            sum = 0;
            dfs(i , j);
            MAXX = max(MAXX , sum);
        }
    }
    printf("%d" , MAXX);
}
