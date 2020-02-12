//
//  2637_장난감조립.cpp
//  summer_week6_위상 정렬
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int N,M;
int in[104];
int base[104];
vector<int> item;
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;

int main(){
    scanf("%d" , &N);
    scanf("%d" , &M);
    vt.resize(N+1);
    item.resize(N+1);
    for (int i = 0; i < M; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt[a].push_back({b,c});
        in[b]++;
        base[a] = -1;
    }
    for (int i =1; i <=N; i++) {
        if(base[i] != -1) item[i] = 0;
        else item[i] = -1;
    }
    
    pq.push({N,1});
    while (!pq.empty()) {
        int here = pq.top().first;
        int cnt = pq.top().second;
        pq.pop();
        
        base[here] += cnt;
        
        for (int i = 0 ; i < vt[here].size(); i++) {
            int there = vt[here][i].first;
            int need = vt[here][i].second;
            
            in[there]--;
            pq.push({there,cnt*need});
        }
    }
    
    for (int i = 1; i<=N; i++) {
        if(item[i] == -1)continue;
        printf("%d %d\n" , i , base[i]);
    }
}
