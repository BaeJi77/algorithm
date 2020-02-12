//  https://www.acmicpc.net/problem/6497
//  6497_전력난.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,minn,total,p[200004];
vector<pair<int, pair<int, int>>> vt;

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}


int main(){
    while (scanf("%d %d" , &m,&n)) {
        if(m==0 && n==0) break;
        total=0; minn=0;
        vt.clear();
        for (int i = 0 ; i < m; i++) {
            p[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int a,b,c;
            scanf("%d %d %d" , &a,&b,&c);
            total += c;
            vt.push_back({c,{a,b}});
        }
        sort(vt.begin(),vt.end());
        
        for (int i = 0; i < n; i++) {
            int w = vt[i].first;
            int a = vt[i].second.first;
            int b = vt[i].second.second;
            
            if(Merge(a, b)){
                minn += w;
            }
        }

        printf("%d\n" , total - minn );
    }
}
