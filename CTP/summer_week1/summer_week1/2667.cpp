//
//  2667.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 2..
//  Copyright © 2018년 Hoon. All rights reserved.
//

using namespace std;
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>

queue<int> qu;
int map[30][30];
vector<int> result;
int n , cnt;
string str1;
bool visited[30][30];

int xx[4] = { 1 , -1 , 0 , 0 };
int yy[4] = { 0 , 0 , 1 , -1 };

//TODO : bfs로 풀어보기
//void bfs(int here){
//    visited[here] = true;
//    qu.push(here);
//    while(qu.size()){
//        int next = qu.front();
//        qu.pop();
//        for (int i = 0; i < map[next].size(); i++) {
//            for (int j = 0; j < 4; j++) {
//                int dx = xx[j]
//            }
//        }
//    }
//}

void dfs(int x , int y){
    visited[x][y] = true;
    cnt++;
    for(int i = 0 ; i < 4 ; i++){
        int dx = x + xx[i];
        int dy = y + yy[i];
        
        if(dx >= 0 && dy >= 0 && dx < n && dy < n){
            if(visited[dx][dy] == false && map[dx][dy] == 1) dfs(dx,dy);
        }
//        if(dx < 0 || dy < 0 || dx > 25 || dy >25) continue;
//        if(visited[dx][dy] == true) continue;
//        if(map[dx][dy] == 0) continue;
//        dfs(dx,dy);
    }
}


int main(){
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        cin>>str1;
        for (int j = 0; j < n; j++) {
            map[i][j] = str1[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0 ; j < n ; j++){
            if(visited[i][j] == false && map[i][j] == 1){
                dfs(i , j);
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(result.begin() , result.end());
    printf("%d\n" , result.size());
    for (int i = 0 ; i < result.size(); i++) {
        printf("%d\n" , result[i]);
    }
}

