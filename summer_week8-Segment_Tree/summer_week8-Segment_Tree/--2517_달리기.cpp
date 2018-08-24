//  https://www.acmicpc.net/problem/2517
//  2517_달리기.cpp
//  summer_week8-Segment_Tree
//
//  Created by Hoon on 2018. 8. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define MAX 500000
#include <climits>
using namespace std;

int n,seg[4*MAX+4],result[MAX+4];
pair<int, int> arr[MAX+4];

int update(int pos, int val, int node, int x, int y){
    if(y < pos || pos < x)
        return seg[node];
    if(x==y)
        return seg[node] = val;
    int mid = (x+y)/2;
    return seg[node] = max(update(pos, val, node*2, x, mid) , update(pos, val, node*2+1, mid+1, y));
}

int query(int lo,int hi,int node,int x,int y){
    if(y < lo || hi < x)
        return INT_MIN;
    if(lo <= x && y <= hi)
        return seg[node];
    int mid = (x+y)/2;
    return max(query(lo, hi, node*2, x, mid) , query(lo, hi, node*2+1, mid+1, y));
}

int main(){
    scanf("%d" , &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d",&a);
        arr[i] = make_pair(a, i);
        result[i] = i;
    }
    
    sort(arr+1,arr+n+1 , [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first > b.first;
    });
    
    
//    sort(arr , arr+n+1 , [](const pair<ll, ll> &a , const pair<ll, ll> &b){
//        if(a.first != b.first) return a.first < b.first;
//        return a.second > b.second;
//    });
    
    for (int i = 1; i<=n; i++) {
        int Q = query(1, arr[i].second, 1, 1, n);
//        result[arr[i].second] = Q;
        printf("%d %d\n" , arr[i].first,arr[i].second);
        update(arr[i].second, Q+1, 1, 1, n);
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n" , query(i, i, 1, 1, n));
    }
    puts("");
}
