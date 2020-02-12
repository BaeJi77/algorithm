//  https://www.acmicpc.net/problem/2243
//  2243_사탕상자.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>


#define MAX 1000000
using namespace std;

int N,seg[MAX*4+4];

int update(int pos,int value,int node,int x,int y){
    if(y < pos || pos < x)
        return seg[node];
    if(x==y)
        return seg[node] += value;
    
    int mid = (x+y)/2;
    return seg[node] = update(pos, value, node*2, x, mid) + update(pos, value, node*2+1, mid+1, y);
}

int query(int number,int node,int x,int y){
    if(x==y){
        update(x, -1, 1, 1, MAX);
        return x;
    }
    
    int mid = (x+y)/2;
    if(seg[node*2] >= number)
        return query(number, node*2, x, mid);
    else
        return query(number - seg[node*2], node*2+1, mid+1, y);
}

int main(){
    scanf("%d" , &N);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d" , &a);
        if(a == 1){
            int b;
            scanf("%d" , &b);
            printf("%d\n" , query(b, 1, 1, MAX));
        }else if(a == 2){
            int b,c;
            scanf("%d %d" , &b,&c);
            update(b, c, 1, 1, MAX);
        }
    }
}
