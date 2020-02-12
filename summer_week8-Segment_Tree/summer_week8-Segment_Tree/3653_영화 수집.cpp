//  https://www.acmicpc.net/problem/3653
//  3653_영화 수집.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#define MAX 100000
using namespace std;

int n,m,seg[8*MAX+4],real[4*MAX+4];

int update(int pos, int val, int node, int x,int y){
    if(y < pos || pos < x)
        return seg[node];
    if(x==y)
        return seg[node] = val;
    int mid = (x+y)/2;
    return seg[node] = update(pos, val, node*2, x, mid) + update(pos, val, node*2+1, mid+1, y);
}

int query(int lo, int hi, int node, int x, int y){
    if(y < lo || hi < x)
        return 0;
    if(lo <= x && y <= hi)
        return seg[node];
    int mid = (x+y)/2;
    return query(lo, hi, node*2, x, mid) + query(lo, hi, node*2+1, mid+1, y);
}

int main(){
    int test;
    scanf("%d" , &test);
    while (test--) {
        memset(seg,0,sizeof(seg));
        memset(real,0,sizeof(real));
        scanf("%d %d" , &n,&m);
        int idx = m+1;
        for (int i = idx; i <= n+m; i++) {
            real[i-m] = i;
            update(i, 1, 1, 1, n+m);
        }
        
        idx = m;
        for (int i = 0; i < m; i++) {
            int a;
            scanf("%d" , &a);
            printf("%d " , query(1, real[a]-1, 1, 1, n+m));
            update(real[a], 0, 1, 1, n+m);
            real[a] = idx--;
            update(real[a], 1, 1, 1, n+m);
        }
        puts("");
    }
}
