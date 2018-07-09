//
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
int n,m,bit,cnt;
queue <pair<int, int>> qu;
//bool visited[30][30];
string input;
int X[] = {1,-1,0,0};
int Y[] = {0,0,1,-1};

bool isposs(int y,int x){
    return (x>=0) && (y>=0) && (x<m) && (y<n);
}

void bfs(int y, int x){
    qu.push({y,x});
    int toNum = map[y][x];
    bit = bit|(1<<toNum);
    while (int s = qu.size()) {
        while (s--) {
            int dy = qu.front().first;
            int dx = qu.front().second;
            cnt++;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int yy = dy + Y[i];
                int xx = dx + X[i];
                if (isposs(yy, xx)) {
                    int temp = map[yy][xx];
                    int bittemp = bit&(1<<temp); // 0이면 비었구나
                    if(bittemp == 0){
                        bit = bit|(1<<temp);
                        qu.push({yy,xx});
                    }
                }
            }
        }
    }
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
    
    bfs(0,0);
    printf("%d" ,cnt);
}

