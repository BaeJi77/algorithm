//  https://www.acmicpc.net/problem/1944
//  MST_1944.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int N,M,sy,sx;
char map[54][54];
vector<pair<int, int>> vt;
vector<vector<int>> point;

int main(){
    scanf("%d %d" , &N,&M);
    point.resize(N+2);
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < N; j++) {
            scanf("%c" , &map[i][j]);
            if(map[i][j] == 'S'){
                sy = i;
                sx = j;
                vt.push_back({i,j});
            }else if(map[i][j] == 'K'){
                vt.push_back({i,j});
            }
        }
        
        for (int i = 0; i < vt.size(); i++) {
            
        }
        
    }
}
