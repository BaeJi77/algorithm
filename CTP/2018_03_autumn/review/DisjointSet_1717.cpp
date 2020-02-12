//  https://www.acmicpc.net/problem/1717
//  DisjointSet_1717.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>

#define MAX 1000000
using namespace std;

int N,M,p[MAX+4];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int Merge(int a,int b){
    int aa = find(a);
    int bb = find(b);
    
    if(aa==bb)
        return -1;
    
    p[aa] = bb;
    return 1;
}

void init(){
    memset(p,-1,sizeof(p));
}

int main(){
    scanf("%d %d" , &N,&M);
    init();
    for (int i = 0; i < M; i++) {
        int q,a,b;
        scanf("%d %d %d" , &q,&a,&b);
        if(q == 0){
            Merge(a, b);
        }else{
            if(find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
