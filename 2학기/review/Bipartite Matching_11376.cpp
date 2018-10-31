//  https://www.acmicpc.net/problem/11376
//  Bipartite Matching_11376.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//
#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX 1000
using namespace std;

int N,M,A[2*MAX+4],B[MAX+4];
vector<int> vt[2*MAX+4];
bool visited[MAX+4];

bool dfs(int a){
    for(int b : vt[a]){
        if(visited[b]) continue;
        visited[b] = true;
        if(B[b] == -1 || dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}



int main(){
    scanf("%d %d" , &N,&M);
    for (int i = 0 ; i < M; i++) {
        int a;
        scanf("%d" , &a);
        for (int j = 0 ; j < a; j++) {
            int b;
            scanf("%d" , &b);
            vt[i*2].push_back(b-1);
            vt[i*2+1].push_back(b-1);
        }
    }
    
    memset(A,-1,sizeof(A));
    memset(B,-1,sizeof(B));
    int result=0;
    for (int i = 0 ; i < 2*N; i++) {
        memset(visited,0,sizeof(visited));
        result += dfs(i);
    }
    
    printf("%d" , result);
}
