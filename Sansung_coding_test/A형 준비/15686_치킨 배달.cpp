//
//  15686_치킨 배달.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 7..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define MAX 50
using namespace std;

int N,K,map[MAX+4][MAX+4];
vector<pair<int, int>> home;
vector<pair<int, int>> chi;

int dist(int y1,int x1,int y2,int x2){
    return (abs(y1-y2)+abs(x1-x2));
}

int cal(int number){
    vector<pair<int, int>> temp;
    for (int i = 0; i < chi.size(); i++) {
        if(number & (1<<i))
            temp.push_back({chi[i].first,chi[i].second});
    }
    
    int ret = 0;
    for (int i = 0 ; i < home.size(); i++) {
        int tempdist = INT_MAX;
        for (int j = 0; j < temp.size(); j++) {
            tempdist = min(tempdist , dist(home[i].first,home[i].second,temp[j].first,temp[j].second));
        }
        ret += tempdist;
    }
    
    return ret;
}

int main(){
    scanf("%d %d" , &N,&K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N ;j++) {
            scanf("%d" , &map[i][j]);
            if(map[i][j] == 1){
                home.push_back({i,j});
            }else if(map[i][j] ==2){
                chi.push_back({i,j});
            }
        }
    }
    
    int ans = INT_MAX;
    int csize = chi.size();
    for (int i = 0 ; i < (1<<csize); i++) {
        int cnt = 0;
        for (int j = 0 ; j < csize; j++) {
            if(i & (1<<j))
                cnt++;
        }
        if(cnt == K){
            ans = min(ans , cal(i));
        }
    }
    
    printf("%d" , ans);
}
