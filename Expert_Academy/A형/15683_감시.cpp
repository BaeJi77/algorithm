//
//  15683_감시.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX 8
using namespace std;

int N,M,map[MAX+1][MAX+1],visited[MAX+1][MAX+1];
int minn;

void check(int y,int x,int dir,int flag){
    //북0 동1 남2 서3
    if(dir == 0){
        for (int i = y+1; i < N; i++) {
            if(map[i][x] == 6)
                break;
            
            if(flag == 0)
                visited[i][x]++;
            else
                visited[i][x]--;
        }
    }else if(dir == 1){
        for (int i = x+1; i < M; i++) {
            if(map[y][i] == 6)
                break;
            
            if(flag == 0)
                visited[y][i]++;
            else
                visited[y][i]--;
        }
    }else if(dir == 2){
        for (int i = y-1; i >= 0; i--) {
            if(map[i][x] == 6)
                break;
            
            if(flag == 0)
                visited[i][x]++;
            else
                visited[i][x]--;
        }
    }else if(dir == 3){
        for (int i = x-1; i >= 0; i--) {
            if(map[y][i] == 6)
                break;
            
            if(flag == 0)
                visited[y][i]++;
            else
                visited[y][i]--;
        }
    }
}

int countZero(){
    int cnt=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
//            if(visited[i][j]) printf("# ");
//            else printf("0 ");

            if(map[i][j] == 6)
                continue;
            if(visited[i][j] == 0)
                cnt++;
        }
//        puts("");
    }
//    puts("");
    return cnt;
}


void solve(vector<pair<int, pair<int, int>>> &v, int idx){
    if(v.size() == idx){
        //탐색을 해서 값들끼리 비교해주면 됨. 가장 작은 값 찾기
        minn = min(minn , countZero());
        return;
    }else{
        int number = v[idx].first;
        int y = v[idx].second.first;
        int x = v[idx].second.second;
        
        if(number == 1){
            for (int i = 0; i < 4; i++) {
                check(y, x, i, 0);
                solve(v, idx+1);
                check(y, x, i, 1);
            }
        }else if(number == 2){
            for (int i = 0; i < 2; i++) {
                check(y, x, i, 0);
                check(y, x, i+2, 0);
                solve(v,idx+1);
                check(y, x, i+2, 1);
                check(y, x, i, 1);
            }
        }else if(number == 3){
            for (int i = 0; i < 4; i++) {
                check(y, x, i, 0);
                check(y, x, (i+1)%4, 0);
                solve(v,idx+1);
                check(y, x, i, 1);
                check(y, x, (i+1)%4, 1);
            }
        }else if(number == 4){
            for (int i = 0; i < 4; i++) {
                check(y, x, i, 0);
                check(y, x, (i+1)%4, 0);
                check(y, x, (i+2)%4, 0);
                solve(v,idx+1);
                check(y, x, i, 1);
                check(y, x, (i+1)%4, 1);
                check(y, x, (i+2)%4, 1);
            }
        }else if(number == 5){
            check(y, x, 0, 0);
            check(y, x, 1, 0);
            check(y, x, 2, 0);
            check(y, x, 3, 0);
            solve(v,idx+1);
            check(y, x, 0, 1);
            check(y, x, 1, 1);
            check(y, x, 2, 1);
            check(y, x, 3, 1);
        }
    }
}

int main(){
    scanf("%d %d" , &N,&M);
    vector<pair<int,pair<int, int>>> vt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d" , &map[i][j]);
            if(1 <= map[i][j] && map[i][j] <= 5){
                vt.push_back({map[i][j],{i,j}});
                visited[i][j] = 1;
            }
        }
    }
    
    minn = INT_MAX;
    solve(vt,0);
    printf("%d" , minn);
}


