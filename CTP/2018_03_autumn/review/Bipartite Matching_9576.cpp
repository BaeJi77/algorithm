//  https://www.acmicpc.net/problem/9576
//  Bipartite Matching_9576.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 1000
using namespace std;

int N,M;
int A[MAX+4],B[MAX+4];
vector<int> vt[MAX+4];
bool visited[MAX+4];

bool dfs(int a){
    for (int b : vt[a]){
        if(visited[b] == true)
            continue;
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
    int test;
    scanf("%d" , &test);
    while (test--) {
        scanf("%d %d" , &N,&M);
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        
        for (int i = 1; i <= M; i++) {
            int a,b;
            scanf("%d %d" , &a,&b);
            vt[i].clear();
            for (int j = a; j <= b; j++) {
                vt[i].push_back(j);
            }
        }
        
        int result = 0;
        for (int i = 1; i <= M; i++) {
            memset(visited,0,sizeof(visited));
            result += dfs(i);
        }
        printf("%d\n" , result);
    }
}

