//  https://www.acmicpc.net/problem/9470
//  9470_Strahler 순서.cpp
//  summer_week6_위상 정렬
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int test,K,M,P;
priority_queue<int> pq;

int main(){
    scanf("%d" , &test);
    while (test--) {
        scanf("%d %d %d" , &K,&M,&P);
        vector<vector<int>> vt(M+1);
        int in[M+1];
        pair<int, int> Stra[M+1];
        memset(in,0,sizeof(in));
        memset(Stra,0,sizeof(Stra));
        
        for (int i = 0; i < P; i++) {
            int a,b;
            scanf("%d %d" , &a,&b);
            vt[a].push_back(b);
            in[b]++;
        }
        
        for (int i = 1; i <= M; i++) {
            if(in[i]==0){
                pq.push(-i);
                Stra[i].first = 1;
            }
        }
        
        while (!pq.empty()) {
            int here = -pq.top();
            pq.pop();
            
            for (int i = 0; i < vt[here].size(); i++) {
                int there = vt[here][i];
                
                if(Stra[here].first > Stra[there].first) {
                    Stra[there].first = Stra[here].first;
                    Stra[there].second = 1;
                }else if(Stra[there].first == Stra[here].first){
                    Stra[there].second++;
                }
                
                if(Stra[there].second>=2) {
                    Stra[there].first++;
                    Stra[there].second=0;
                }
                
                in[there]--;
                if(in[there]==0) pq.push(-there);
            }
        }
        
        printf("%d %d\n" , K, Stra[M].first);
    }
}
