//  https://www.acmicpc.net/problem/1321
//  1321_군인.cpp
//  1week_Segment Tree
//
//  Created by Hoon on 2018. 9. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>


#define MAX 500000
using namespace std;

int N,seg[4*MAX+4],K;

int update(int pos,int value,int node,int x,int y){
    if(y < pos || pos < x)
        return seg[node];
    if(y==x)
        return seg[node] += value;
    int mid = (x+y)/2;
    return seg[node] = update(pos, value, node*2, x, mid) + update(pos, value, node*2+1, mid+1, y);
}

int query(int number,int node,int x,int y){
    if(x==y)
        return x;
    
    int mid = (x+y)/2;
    if(seg[node*2] >= number)
        return query(number, node*2, x, mid);
    else
        return query(number - seg[node*2], node*2+1, mid+1, y);
}



int main() {
    scanf("%d" , &N);
    for (int i = 1; i <= N; i++) {
        int input;
        scanf("%d" , &input);
        update(i, input, 1, 1, N);
    }
    scanf("%d" , &K);
    for (int i = 0; i < K; i++) {
        int a;
        scanf("%d" ,&a);
        if(a == 1){
            int b,c;
            scanf("%d %d" , &b,&c);
            update(b, c, 1, 1, N);
        }else if(a==2){
            int b;
            scanf("%d" , &b);
            printf("%d\n" , query(b, 1, 1, N));
        }
    }
}


