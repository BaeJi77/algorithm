//  https://www.acmicpc.net/problem/14950
//  14950_정복자.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 17..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,t,p[100004];
long long ans;
vector<pair<int, pair<int, int>>> vt;

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

bool Merge(int u , int v){
    int uu = Find(u);
    int vv = Find(v);
    if(uu == vv) return false;
    p[uu] = vv;
    return true;
}

void init(){
    for (int i = 0; i<=n; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d %d %d" , &n,&m,&t);
    init();
    for (int i = 0; i < m ; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    sort(vt.begin(),vt.end());
    
    for (int i = 0; i < m; i++) {
        int w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Merge(a, b)) ans += w;
    }
//    printf("%lld\n" , ans);
    ans += (n-2)*t*(n-2+1)/2;
    printf("%lld" , ans);
}
