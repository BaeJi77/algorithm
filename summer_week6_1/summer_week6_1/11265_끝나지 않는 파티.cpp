//
//  11265_끝나지 않는 파티.cpp
//  summer_week6_1
//
//  Created by Hoon on 2018. 8. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>

using namespace std;

int n,m;
int dist[504][504];

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j <=n ; j++) {
            scanf("%d" , &dist[i][j]);
        }
    }
    
    for (int i =1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            for (int k = 1; k <=n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    while (m--) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        if(c>= dist[a][b]) printf("Enjoy other party\n");
        else printf("Stay here\n");
    }
}
