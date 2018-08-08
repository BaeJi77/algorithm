//  https://www.acmicpc.net/problem/11000
//  11000_강의실 배정.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

int n;
queue<int> qu;
priority_queue<pair<int, int>> pq;

int main(){
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        pq.push({-a,b});
    }
    
    
}
