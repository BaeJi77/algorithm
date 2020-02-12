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

int n,m,p[100004],cnt,sum;
vector<pair<int, pair<int, int>>> vt;

void init(){
    for (int i = 0; i <=n; i++) {
        p[i] = i;
    }
}

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

bool Merge(int u , int v){
    int uu = Find(u);
    int vv = Find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}

int main(){
    scanf("%d %d" , &n,&m);
    init();
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    
    sort(vt.begin(),vt.end());
    
    for (int i = 0; i < m; i++) {
        if(cnt == n-2) break;
        int w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a)==Find(b)) continue;
        Merge(a, b);
        sum += w;
        cnt++;
    }
    printf("%d"  , sum);
}
