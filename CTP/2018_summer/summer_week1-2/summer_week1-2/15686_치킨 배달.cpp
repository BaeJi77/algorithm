//  https://www.acmicpc.net/problem/15686
//  15686_치킨 배달.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 22..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n,m,map[54][54];
vector<pair<int, int>> house;
vector<pair<int, int>> chi;

int dist(int x1,int y1, int x2, int y2){
    return (abs(x1-x2) + abs(y1-y2));
}

int cal(int x){
    vector<pair<int, int>> vt;
    for (int i = 0 ; i < chi.size(); i++) {
        if(x & (1<<i)) vt.push_back({chi[i].first,chi[i].second});
    }
    
    int ret = 0;
    for (int i = 0; i < house.size(); i++) {
        int dis = INT_MAX;
        for (int j = 0; j < vt.size(); j++) {
            dis = min(dis , dist(house[i].first , house[i].second , vt[j].first , vt[j].second));
        }
        ret += dis;
    }
    
    return ret;
}


int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d" , &map[i][j]);
            if(map[i][j] == 1) house.push_back({i,j});
            if(map[i][j] == 2) chi.push_back({i,j});
        }
    }
    
    int ans = INT_MAX;
    int chiCnt = chi.size();
    for (int i = 0; i < (1<<chiCnt); i++) {
        int cnt = 0;
        for (int j = 0; j < chiCnt; j++) {
            if(i & (1<<j)) cnt++;
        }
        if(cnt == m){
            ans = min(ans , cal(i));
        }
    }
    
    printf("%d" ,ans);
}
