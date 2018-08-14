//  https://www.acmicpc.net/problem/12893
//  12893_적의적.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
using namespace std;

int n,m,ans;
int p[2004];
int check[2004];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    if(uu==vv) return false;
    p[vv] = uu;
    return true;
}

int main(){
    scanf("%d %d" , &n,&m);
    memset(p,-1,sizeof(p));
    while (m--) {
        int a,b;
        scanf("%d %d" , &a,&b);
        Merge(a,b);
    }
    
    int root = find(1);
    for (int i = 1; i <=n; i++) {
        if(root == find(i)){
            check[i] = -1;
        }
    }
    
    for (int i = 1; i<=n; i++) {
        if(check[i] == -1){
            ans = 1;
        }else {
            ans = 0;
            break;
        }
    }
    
    if(ans == 1) printf("0");
    else printf("1");
    
}
