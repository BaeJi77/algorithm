//  https://www.acmicpc.net/problem/1321
//  1321_군인.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int n,q,seg[2000004];

int update(int pos , int val, int node, int x, int y){
    if(y < pos || pos < x) return seg[node];
    if(x==y) return seg[node] += val;
    int mid = (x+y)/2;
    return seg[node] = update(pos, val, node*2, x, mid) + update(pos, val, node*2+1, mid+1, y);
}

int query(int val, int node, int x, int y){
    if(x==y)
        return x;
    
    int mid = (x+y)/2;
    if(seg[node*2] >= val)
        return query(val, node*2, x, mid);
    else
        return query(val - seg[node*2], node*2+1, mid+1 , y);
}



int main(){
    scanf("%d" , &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d" , &a);
        update(i, a, 1, 1, n);
    }
    
    scanf("%d" , &q);
    for (int i = 0; i < q; i++) {
        int a,b,c;
        scanf("%d %d" , &a,&b);
        if(a == 1){
            scanf("%d" , &c);
            update(b, c, 1, 1, n);
        }else if(a == 2){
            printf("%d\n" , query(b,1,1,n));
        }
    }
}
