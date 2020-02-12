//  https://www.acmicpc.net/problem/11404
//  11404_플로이드.cpp
//  summer_week6_1
//
//  Created by Hoon on 2018. 8. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int n,m;
int dist[104][104];

int main() {
    scanf("%d" , &n);
    scanf("%d" , &m);
    
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            if(i==j) continue;
            dist[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        dist[a][b] = min(dist[a][b] , c);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            for (int k = 1; k <= n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            if(dist[i][j] == INF) printf("0 ");
            else printf("%d " , dist[i][j]);
        }
        puts("");
    }
}
