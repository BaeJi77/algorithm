//  https://www.acmicpc.net/problem/1854
//  1854_k번째 최단경로 찾기.cpp
//  summer_week5-1
//
//  Created by Hoon on 2018. 8. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m,k;
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;
priority_queue<int> pqArray[1004];

void dij(){
    pq.push({0,1});
    pqArray[1].push(0);
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        for(auto i : vt[here]){
            int there = i.first;
            int ncost = i.second + cost;
            
            if(pqArray[there].size() < k){
                pqArray[there].push(ncost);
            }else if(pqArray[there].top() > ncost){
                pqArray[there].pop();
                pqArray[there].push(ncost);
            }else
                continue;
            pq.push({-ncost,there});
        }
    }
}

int main(){
    scanf("%d %d %d" , &n,&m,&k);
    vt.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt[a].push_back({b,c});
    }
    
    dij();
    for (int i = 1; i <= n; i++) {
        if(pqArray[i].size() != k) printf("-1\n");
        else printf("%d\n" , pqArray[i].top());
    }
}
