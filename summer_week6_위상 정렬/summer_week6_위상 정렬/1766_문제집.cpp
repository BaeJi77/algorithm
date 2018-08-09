//
//  1766_문제집.cpp
//  summer_week6_위상 정렬
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int in[32004];
vector<vector<int>> vt;
priority_queue<int> pq;

int main(){
    scanf("%d %d" , &n,&m);
    vt.resize(n+1);
    for (int i = 0 ; i < m; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        vt[a].push_back(b);
        in[b]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if(in[i]==0) pq.push(-i);
    }
    
    while (!pq.empty()) {
        int here = -pq.top();
        pq.pop();
        printf("%d " ,  here);
        
        for (int i = 0; i < vt[here].size(); i++) {
            int there = vt[here][i];
            in[there]--;
            if(in[there] == 0) pq.push(-there);
        }
    }
}
