//  https://www.acmicpc.net/problem/10971
//  10971_외판원 순회 2.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 21..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXX 987654321


int N,W[14][14];
bool visited[14];
int ans = MAXX;

void tsp(int node , int nowSum , int count){
    if(count == N) {
        if(W[node][0] != 0) //시작점으로 가는 길이 있다면
            ans = min(ans,nowSum+W[node][0]);
        return;
    }
    
    visited[node] = true;
    for (int i = 0; i < N; i++) {
        if(visited[i] == false && W[node][i] != 0){
            if(nowSum + W[node][i] < ans){
                tsp(i , nowSum + W[node][i] , count+1);
            }
        }
    }
    visited[node] = false;
}

int main(){
    scanf("%d" , &N);
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d" , &W[i][j]);
        }
    }
    
    tsp(0,0,1);
    printf("%d" , ans);
}
