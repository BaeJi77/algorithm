//  https://www.acmicpc.net/problem/1516
//  1516_게임 개발.cpp
//  summer_week6_위상 정렬
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n;
int cost[504];
int preCost[504];
int in[504];
vector<vector<int>> vt;
priority_queue<int> pq;
int w[501];
int main(){
    scanf("%d" , &n);
    vt.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int pp = 0;
        vector<int> nvt;
        while (scanf("%d" , &pp)) {
            if(pp==-1) break;
            nvt.push_back(pp);
        }
        cost[i] = nvt[0];
        w[i]=nvt[0];
        for (int  j =  1; j < nvt.size(); j++) {
            vt[nvt[j]].push_back(i);
            in[i]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if(in[i]==0) pq.push(-i);
    }
    
    while (!pq.empty()) {
        int here = -pq.top();
        pq.pop();
        for(int i = 0;i<vt[here].size();i++)
        {
            int there = vt[here][i];
            w[there]=max(w[there],w[here]+cost[there]);
            in[there]--;
            if(in[there] == 0 ) pq.push(-there);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n" , w[i]);
    }
}
