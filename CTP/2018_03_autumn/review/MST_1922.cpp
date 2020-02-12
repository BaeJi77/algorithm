//  https://www.acmicpc.net/problem/1922
//  MST_1922.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 10000
using namespace std;

int N,M,p[MAX+4];
vector<pair<int, pair<int, int>>> vt;

int ffind(int x){
    if(p[x] < 0) return x;
    return p[x] = ffind(p[x]);
}

int Merge(int a,int b){
    int aa = ffind(a);
    int bb = ffind(b);
    if(aa==bb)
        return false;
    p[aa] = bb;
    return true;
}

int main(){
    scanf("%d",&N);
    scanf("%d" , &M);
    memset(p,-1,sizeof(p));
    for (int i = 0; i < M; i++) {
        int a,b,c;
        scanf("%d %d %d" ,&a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    sort(vt.begin(),vt.end());
    int ans = 0;
    for (int i = 0 ; i < M; i++) {
        int cost = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Merge(a, b) == true){
            ans += cost;
        }
    }
    
    printf("%d" , ans);
}
