//
//  2583.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,k,cnt,a,b,c,d; //n이 x좌표 m이 y좌표
bool check[110][110];
int map[110][110];
vector<int> result;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int y,int x){
    check[y][x] = true;
    cnt++;
    for (int i = 0 ; i < 4; i++) {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        if(check[yy][xx] == true) continue;
        if(map[yy][xx] == true) continue;
        dfs(yy,xx);
    }
}

int main(){
    scanf("%d %d %d", &m,&n,&k);
    while (k--) {
        scanf("%d %d %d %d" , &a,&b,&c,&d); // (a,b) (c,d)
        for (int i = b; i < d; i++) {
            for (int j = a; j < c; j++) {
                map[i][j] = 1;
            }
        }
    }

//    for (int i = 0 ; i < m; i++) {
//        for (int j = 0 ; j < n; j++) {
//            printf("%d ",map[i][j]);
//        }
//        printf("\n");
//    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] == false && check[i][j] == false){
                cnt=0;
                dfs(i,j);
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n",result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("%d " , result[i]);
    }
}



