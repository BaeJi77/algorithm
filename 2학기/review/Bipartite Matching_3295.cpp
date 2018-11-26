//  https://www.acmicpc.net/problem/3295
//  Bipartite Matching_3295.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX 50000
using namespace std;

int N,M,A[1004],B[1004];
vector<int> adj[MAX+4];
bool visited[1004];

bool dfs(int a){
    for(int b : adj[a]){
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
    int t;
    scanf("%d" , &t);
    while (t--) {
        scanf("%d %d" , &N,&M);
        memset(A,-1,sizeof(A));
        memset(B,-1,sizeof(B));
        for(int i = 0 ; i < N ; i++)
            adj[i].clear();
        
        for (int i = 0 ; i < M; i++) {
            int a,b;
            scanf("%d %d" ,&a,&b);
            adj[b].push_back(a);
        }
        
        int result = 0;
        for (int i = 0; i < N; i++) {
            memset(visited,0,sizeof(visited));
            result += dfs(i);
        }
        printf("%d\n" , result);
    }
}
