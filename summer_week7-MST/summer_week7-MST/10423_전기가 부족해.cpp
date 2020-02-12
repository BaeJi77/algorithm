//  https://www.acmicpc.net/problem/10423
//  10423_전기가 부족해.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k,p[1004],cnt;
//bool visited[1004];
int e[1004];
vector<pair<int, pair<int, int>>> vt;

void init(){
    memset(p,-1,sizeof(p));
    memset(e,-1,sizeof(e));
}

int Find(int x){
    if(p[x] == -1) return x;
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
    scanf("%d %d %d" , &n,&m,&k);
    init();
    for (int i = 0; i < k; i++) {
        int a;
        scanf("%d" , &a);
        p[a] = a;
        e[a] = a;
    }
    
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vt.push_back({c,{a,b}});
    }
    
    sort(vt.begin(),vt.end());
    
    for (int i = 0; i < m; i++) {
        int w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a) == Find(b)) continue;
        if(e[Find(a)] != -1 && e[Find(b)] != -1) continue;
        if(e[Find(a)] == -1 && e[Find(b)] == -1) {
            //전기는 이어주지 않아도 됨
        }else if(e[Find(b)] != -1){ // => b의 부모가 전기가 공급이 된다.
            e[Find(a)] = Find(b);
        }else{//e[Find(a)] != -1 =? a의 부모가 전기가 공급이 된다.
            e[Find(b)] = Find(a);
        }
        Merge(a, b);
        cnt+= w;
    }
    
    printf("%d" , cnt);
}

