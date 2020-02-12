//  https://www.acmicpc.net/problem/11000
//  11000_강의실 배정.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n,maxClass;
queue<pair<int, int>> qu;
priority_queue<pair<int, int>> pq;

int main(){
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        pq.push({-a,b});
    }
    
    qu.push({-pq.top().first , pq.top().second});
    pq.pop();
    maxClass = 1;
    
    while (!pq.empty()) {
        int start = -pq.top().first;
        int end = pq.top().second;
        pq.pop();
        
        if(qu.front().second < start){
            qu.push({start,end});
            
        }
        while (qu.front().second >= start) {
            qu.pop();
        }
        
    }
}
