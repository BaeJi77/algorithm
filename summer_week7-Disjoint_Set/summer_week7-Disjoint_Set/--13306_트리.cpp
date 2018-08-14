//  https://www.acmicpc.net/problem/13306
//  13306_트리.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
using namespace std;

int N,Q,zeroCnt,oneCnt;
int p[200004];

int find(int x){
    if(p[x] == -1) return x;
//    p[x] = find(p[x]);
    return find(p[x]);
}

bool Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    
    if(uu == vv) return false;
//    p[vv] = uu;
    return true;
}

int main(){
    scanf("%d %d" , &N,&Q);
    memset(p,-1,sizeof(p));
    p[1] = -1;
    for (int i = 2; i <= N; i++) {
        int a;
        scanf("%d" , &a);
        p[i] = a;
    }
    
    while (1) {
        int Num;
        scanf("%d" , &Num);
        if(Num == 1){
            oneCnt++;
            int a,b;
            scanf("%d %d" , &a,&b);
            //같은 부모인지 확인하기
            if(!Merge(a, b)) printf("YES\n");
            else printf("NO\n");
        }else if(Num == 0){
            zeroCnt++;
            int a;
            scanf("%d" , &a);
            p[a] = -1;
        }
        
        if(oneCnt == Q && zeroCnt == N-1) break;
    }
}
