//  https://www.acmicpc.net/problem/1647
//  1647_도시 분할 계획.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<pair<int, pair<int, int>>> vt;

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    
}
