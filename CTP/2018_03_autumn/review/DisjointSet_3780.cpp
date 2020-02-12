//  https://www.acmicpc.net/problem/3780
//  DisjointSet_3780.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MAX 20000
using namespace std;
typedef pair<int,int> P;

int dist[MAX+4],p[MAX+4];

P find(int x){
    if(p[x] < 0) return P(x,0);
    P next = find(p[x]);
    p[x] = next.first;
    dist[x] += next.second;
    return P(p[x],dist[x]);
}

void Merge(int a,int b){
    int aCenter = find(a).first;
    int bCenter = find(b).first;
    if(aCenter != bCenter){
        dist[aCenter] = (abs(a-b)%1000);
        p[aCenter] = b;
    }
}

int main(){
    int test;
    scanf("%d ", &test);
    while (test--) {
        memset(dist,0,sizeof(dist));
        memset(p,-1,sizeof(p));
        int N;
        scanf("%d" , &N);
        while (1) {
            getchar();
            char q = getchar();
            if(q == 'O')
                break;
            else if(q== 'E'){
                int x;
                scanf("%d" , &x);
                find(x);
                printf("%d\n" , dist[x]);
            }else if(q == 'I'){
                int a,b;
                scanf("%d %d" , &a,&b);
                Merge(a, b);
            }
        }
    }
}
