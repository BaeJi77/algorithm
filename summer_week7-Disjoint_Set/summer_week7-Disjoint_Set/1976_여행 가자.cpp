//  https://www.acmicpc.net/problem/1976
//  1976_여행 가자.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 13..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

int N,M;
int par[204];
vector<int> vt;

int find(int number){
    if(par[number] < 0) return number;
    par[number] = find(par[number]);
    return par[number];
}

bool Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    
    if(uu==vv) return false;
    
    par[vv] = uu;
    return true;
}

int main(){
    scanf("%d" , &N);
    scanf("%d" , &M);
    memset(par,-1,sizeof(par));
    
    for (int i = 1; i<=N; i++) {
        for (int j = 1 ; j<= N; j++) {
            int a;
            scanf("%d" , &a);
            if(a) Merge(i, j);
        }
    }
    
    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a);
        vt.push_back(a);
    }
    
    bool result = false;
    for (int i = 0; i < vt.size()-1; i++) {
        for (int j = 1; j < vt.size(); j++) {
            if(find(vt[i]) == find(vt[j])) result = true;
            else{
                result = false;
                break;
            }
        }
        if(result == false) break;
    }
    
    if(result) printf("YES");
    else printf("NO");
}
