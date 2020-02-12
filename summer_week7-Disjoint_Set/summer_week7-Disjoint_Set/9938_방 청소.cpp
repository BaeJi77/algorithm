//  https://www.acmicpc.net/problem/9938
//  9938_방 청소.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
using namespace std;

int n,L;
int p[300004];
int check[300004];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    //uu가 부모가 된다.
    p[vv] = uu;
    printf("LADICA\n");
}

void init(){
    for (int i = 1; i<=L; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d %d" , &n,&L);
    memset(check,-1,sizeof(check));
    init();
    for (int i = 1; i <= n; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        if(check[a] < 0){
            //a가 비어있다.
            check[a] = i;
            Merge(b, a);
        }else if(check[b] < 0){
            check[b] = i;
            Merge(a, b);
        }else if(check[find(a)] < 0){
            check[find(a)] = i;
            Merge(b, a);
        }else if(check[find(b)] < 0){
            check[find(b)] = i;
            Merge(a, b);
        }else{
            printf("SMECE\n");
        }
    }
}
