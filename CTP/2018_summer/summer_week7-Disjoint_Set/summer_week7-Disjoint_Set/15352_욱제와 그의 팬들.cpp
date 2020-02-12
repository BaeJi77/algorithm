//  https://www.acmicpc.net/problem/15352
//  15352_욱제와 그의 팬들.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 15..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

int k,n,Q;
long long cnt;
int p[1000004];
int club[1000004];
int sz[1000004];
int L[1000004];
int R[1000004];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    if(uu == vv) return;
    p[vv] = uu;
    sz[uu] += sz[vv];
}

void del(int x){ // x =3
    sz[find(x)]--;
    int LL = L[x]; // LL =2
    int RR = R[x]; // RR = 4
    if(LL != -1) R[LL] = RR; //R[2] = 4;
    if(RR != -1) L[RR] = LL; //L[4] = 2;
    if(club[LL] == club[RR]) Merge(LL, RR);
}

int main(){
    scanf("%d %d" , &k,&n);
    for (int i = 1; i<=n; i++) {
        scanf("%d" , &club[i]);
        p[i] = i;
        sz[i] = 1;
        L[i] = i-1;
        R[i] = i+1;
    }
    
    //-1 => 끝
    L[1] = -1;
    R[n] = -1;
    
    for (int i = 1; i<=n-1; i++) {
        if(club[i] == club[i+1]) Merge(i , i+1);
    }
    
    scanf("%d" , &Q);
    for (int i = 1; i <= Q; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        if(a == 1){
            del(b);
        }else{
            cnt += sz[find(b)];
        }
    }
    printf("%lld", cnt);
}
