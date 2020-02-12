//  https://www.acmicpc.net/problem/2357
//  2357_최소값과 최대값.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 20..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <climits>
using namespace std;

int n,m;
int mseg[400004];
int seg[400004];

int update(int pos, int val, int node, int x, int y){
    if(y < pos || pos < x) return seg[node];
    if(x==y) return seg[node] = val;
    int mid = (x+y)/2;
    int front = update(pos, val, node*2, x, mid);
    int back = update(pos, val, node*2+1, mid+1, y);
    if(front > back){
        return seg[node] = front;
    }else {
        return seg[node] = back;
    }
}

int query(int lo, int hi, int node, int x, int y){
    if(y < lo || hi < x) return INT_MIN;
    if(lo <= x && y <= hi) return seg[node];
    int mid = (x+y)/2;
    int front = query(lo, hi, node*2, x, mid);
    int back = query(lo, hi, node*2+1, mid+1, y);
    if( front> back){
        return front;
    }else {
        return back;
    }
}

int mupdate(int pos, int val, int node, int x, int y){
    if(y < pos || pos < x) return mseg[node];
    if(x==y) return mseg[node] = val;
    int mid = (x+y)/2;
    int front = mupdate(pos, val, node*2, x, mid);
    int back = mupdate(pos, val, node*2+1, mid+1, y);
    if(front < back){
        return mseg[node] = front;
    }else {
        return mseg[node] = back;
    }
}

int mquery(int lo, int hi, int node, int x, int y){
    if(y < lo || hi < x) return INT_MAX;
    if(lo <= x && y <= hi) return mseg[node];
    int mid = (x+y)/2;
    int front = mquery(lo, hi, node*2, x, mid);
    int back = mquery(lo, hi, node*2+1, mid+1, y);
    if( front < back){
        return front;
    }else {
        return back;
    }
}

void init(){
    for (int i = 1; i<=n*4; i++) {
        seg[i] = INT_MIN;
        mseg[i] = INT_MAX;
    }
}

int main(){
    scanf("%d %d" , &n,&m);
    init();
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d" , &a);
        update(i, a, 1, 1, n);
        mupdate(i, a, 1, 1, n);
    }
    
    for (int i = 0; i < m; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        printf("%d %d\n" , mquery(a, b, 1, 1, n),query(a, b, 1, 1, n));
    }
}
