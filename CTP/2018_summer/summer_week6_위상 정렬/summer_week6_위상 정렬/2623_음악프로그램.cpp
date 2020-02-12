//  https://www.acmicpc.net/problem/2623
//  2623_음악프로그램.cpp
//  summer_week6_위상 정렬
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n,m,check;
int in[1004];
int arr[1004];
bool visited[1004];
bool finished[1004];
vector<vector<int>> vt;
priority_queue<int> pq;

void cycleCheck(int here){
    visited[here] = true;
    for (int i = 0; i < vt[here].size(); i++) {
        int there = vt[here][i];
        if(visited[there] == false) cycleCheck(there);
        else if(finished[there] == false) check = 1;
    }
    finished[here] = true;
}

int main(){
    scanf("%d %d" , &n,&m);
    vt.resize(n+1);
    for (int i = 0; i < m; i++) {
        memset(arr,0,sizeof(arr));
        int loop = 0;
        scanf("%d" , &loop);
        for (int j = 0 ; j < loop; j++) {
            scanf("%d" , &arr[j]);
        }
        
        if(loop==1) pq.push(-arr[0]);
        for (int j = 0; j < loop-1; j++) {
            vt[arr[j]].push_back(arr[j+1]);
            in[arr[j+1]]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if(in[i] == 0) pq.push(-i);
    }
    
    cycleCheck(-pq.top());
    if(check == true) printf("0");
    else{
        while (!pq.empty()) {
            int here = -pq.top();
            pq.pop();
            
            printf("%d\n" , here);
            for (int i = 0; i < vt[here].size(); i++) {
                int there = vt[here][i];
                in[there]--;
                if(in[there] == 0) pq.push(-there);
            }
        }
    }
}
