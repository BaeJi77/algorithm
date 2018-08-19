//  https://www.acmicpc.net/problem/2406
//  2406_안정적인 네트워크.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,cnt,cost,p[1004];
vector<pair<int, pair<int, int>>> vt;
vector<pair<int, int>> ans;

void init(){
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
}

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

bool Merge(int u,int v){
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
        int a,b;
        scanf("%d %d" , &a,&b);
        if(Find(a) == Find(b)) continue;
        Merge(a,b);
        cnt++;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            scanf("%d" , &a);
            if(a == 0) continue;
            vt.push_back({a,{i,j}});
        }
    }
    
    sort(vt.begin(),vt.end());
    
    for (int i = 0 ; i < vt.size(); i++) {
        if(cnt == n-1) break;
        int w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a) == Find(b)) continue;
        if(a== 1 || b== 1) continue;
        Merge(a, b);
        cost += w;
        ans.push_back({a,b});
    }
    
    printf("%d %d\n" , cost,ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n" , ans[i].first,ans[i].second);
    }
}
