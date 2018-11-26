//  https://www.acmicpc.net/problem/2188
//  Bipartite Matching_2188.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX 200
using namespace std;

bool visited[MAX+4];
int N,M,A[MAX+4],B[MAX+4];
vector<int> adj[MAX+4];

bool dfs(int x){
    visited[x] = true;
    for(auto i : adj[x]){
        if(B[i] == -1 || (!visited[B[i]] && dfs(B[i]))){
            A[x] = i;
            B[i] = x;
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int S;
        scanf("%d", &S);
        for(int j=0; j<S; j++){
            int k;
            scanf("%d", &k);
            adj[i].push_back(k-1);
        }
    }
    
    int match = 0;
    memset(A,-1,sizeof(A));
    memset(B,-1,sizeof(B));
    for (int i = 0; i < N; i++) {
        if(A[i] == -1){
            memset(visited,0,sizeof(visited));
            if(dfs(i)) match++;
        }
    }
    printf("%d" , match);
}
