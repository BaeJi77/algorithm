//  https://www.acmicpc.net/problem/1197
//  1197_최소 스패닝 트리.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v,e,p[10004],ans;
vector<pair<int, pair<int, int>>> vt;

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool Merge(int u , int v){
    int uu = find(u);
    int vv = find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d" , &v,&e);
    for (int i = 1; i<=v; i++) {
        p[i] = i;
    }
    
    for (int i = 0; i < e; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    sort(vt.begin(),vt.end());
    
    for (int i = 0; i < vt.size(); i++) {
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        int w = vt[i].first;
        
        if(Merge(a,b) == true){
            ans+= w;
        }
    }
    
    printf("%d" , ans);
    
}


