//  https://www.acmicpc.net/problem/1765
//  1765_닭싸움 팀 정하기.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <set>
using namespace std;

int n,m,cnt;
int p[1004];
int e[1004];
int check[1004];
set<int> se;

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    if(uu==vv) return;
    p[vv] = uu;
}

void init(){
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d" , &n);
    scanf("%d" , &m);
    init();
    while (m--) {
        getchar();
        int ch = getchar();
        int a,b;
        scanf("%d %d" , &a,&b);
        if(ch == 'E'){
            if(se.find(a) == se.end()){
                //원소가 존재하지 않다면
                se.insert(a);
                e[a] = b;
            }else{
                //원소가 존재 한다면
                int enermy=e[a];
                Merge(enermy,b);
            }
        }else if(ch == 'F'){
            Merge(a, b);
        }
    }
    
//    for (int i = 1; i<=n; i++) {
//        printf("%d " , find(i));
//    }
//
    cnt = 0;
    for (int i = 1; i<=n; i++) {
        int root = find(i);
        if(check[i] == -1) continue;
        else{
            for (int j = i; j <= n; j++) {
                if(check[j] == -1) continue;
                if(root == find(j)) {
//                    printf("%d %d\n" , i ,j);
                    check[j] = -1;
                }
            }
            cnt++;
        }
    }

    
    printf("%d" , cnt);
}
