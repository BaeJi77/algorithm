//  https://www.acmicpc.net/problem/1306
//  1306_달려라 홍준.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 24..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define MAX 1000000
using namespace std;

int n,m,seg[4*MAX+4];

int update(int pos, int val,int node, int x,int y){
    if(y < pos || pos < x)
        return seg[node];
    if(x==y)
        return seg[node] = val;
    int mid = (x+y)/2;
    return seg[node] = max(update(pos, val, node*2, x, mid) , update(pos, val, node*2+1, mid+1, y));
}

int query(int lo, int hi, int node, int x, int y){
    if(y < lo || hi < x)
        return 0;
    if(lo <= x && y <= hi)
        return seg[node];
    int mid = (x+y)/2;
    return max(query(lo, hi, node*2, x, mid) , query(lo, hi, node*2+1, mid+1, y));
}


int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d" , &a);
        update(i, a, 1, 1, n);
    }
    
    for (int i = m; i<=n-m+1; i++) {
        int ans = query(i-m+1, i+m-1, 1, 1, n);
        printf("%d " , ans);
    }
}
