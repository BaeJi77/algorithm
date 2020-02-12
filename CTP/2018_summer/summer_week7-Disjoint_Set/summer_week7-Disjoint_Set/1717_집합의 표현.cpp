//  https://www.acmicpc.net/problem/1717
//  1717_집합의 표현.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 13..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>

int n,m;
int root[1000004];

int find(int number){
    if(root[number] == number) return number;
    
    return root[number] = find(root[number]);
}

void Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    
    if(uu==vv) return;
    
    root[uu] = vv;
}

int result(int u, int v){
    int uu = find(u);
    int vv = find(v);
    
    if(uu==vv) return 1;
    else return 0;
}

void init(){
    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d" , &n,&m);
    init();
    while (m--) {
        int c,a,b;
        scanf("%d %d %d" , &c,&a,&b);
        if(c==0){
            Merge(a, b);
        }else{
            int ans = result(a,b);
            if(ans == 1) printf("YES\n");
            else printf("NO\n");
        }
    }
}
