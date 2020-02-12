//  https://www.acmicpc.net/problem/11562
//  11562_백양로 브레이크.cpp
//  summer_week6_1
//
//  Created by Hoon on 2018. 8. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>

#define INF 987654321
using namespace std;

int n,m,k;
int dist[254][254];

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i==j) continue;
            dist[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        if(c == 0) {
            dist[a][b] = 0;
            dist[b][a] = 1;
        }
        else if(c==1) {
            dist[a][b] = 0;
            dist[b][a] = 0;
        }
    }
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            for (int k = 1; k <= n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    scanf("%d" , &k);
    for (int i = 0 ; i < k; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        printf("%d\n" , dist[a][b]);
    }
}
