//  https://www.acmicpc.net/problem/14621
//  14621_나만 안되는 연애.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans,cnt,color[1004],p[1004];
vector<pair<int, pair<int, int>>> vt;

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

void init(){
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d %d" , &n,&m);
    init();
    for (int i = 1; i <= n; i++) {
        getchar();
        int col = getchar();
        if(col == 'W') color[i] = 0;
        else color[i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    sort(vt.begin(),vt.end());
    
    for (int i = 0 ; i < m; i++) {
        int w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(color[a] == color[b]) continue;
        if(Find(a) == Find(b)) continue;
        Merge(a,b);
        ans+= w;
        cnt++;
    }
    
    if(cnt != n-1) printf("-1");
    else printf("%d" , ans);
}
