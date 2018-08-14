//  https://www.acmicpc.net/problem/4195
//  4195_친구 네트워크.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 13..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int test,f,cnt;
int par[200004];
int sizef[200004];

int find(int number){
    if(par[number] == number) return number;
    return par[number] = find(par[number]);
}

void Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    
    if(uu == vv) return;
    sizef[vv] += sizef[uu];
    
    par[uu] = vv;
}

int main(){
    scanf("%d" , &test);
    while (test--) {
        scanf("%d" , &f);
        memset(par,0,sizeof(par));
        for(int i=0; i<2*f; i++){
            par[i] = i;
            sizef[i] = 1;
        }
        map<string, int> mp;
        cnt=0;
        while (f--) {
            char a[25], b[25];
            scanf("%s %s", a, b);
            int n1,n2;
            if(mp.count(a) == 0) {
                mp[a] = cnt++;
            }
            n1 = mp[a];
            if(mp.count(b) == 0){
                mp[b] = cnt++;
            }
            n2 = mp[b];
            Merge(n1, n2);
            printf("%d\n" , sizef[par[n2]]);
        }
    }
}
