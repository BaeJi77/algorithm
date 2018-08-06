//
//  2458_키 순서.cpp
//  summer_week6_1
//
//  Created by Hoon on 2018. 8. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <cstring>
#define INF 987654321
using namespace std;

int n,m,totalCnt;
int dist[504][504];
int check[504];

int main(){
    scanf("%d %d" , &n,&m);
    for (int i =1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i==j) continue;
            dist[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        dist[a][b] = 1;
    }
    
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <=n; j++) {
            for (int k = 1; k <= n; k++) {
                //&연산으로 인해 가지 못하면 dist[j][k]를 0으로 바꾼다.
                if(dist[j][k] == 1) continue;
                dist[j][k] = dist[j][i] & dist[i][k];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        memset(check,0,sizeof(check));
        for (int j = 1; j <=n; j++) {
            if(dist[i][j] == 1) check[j] = 1;
            if(dist[j][i] == 1) check[j] = 1;
        }
        
        for (int j = 1; j <= n; j++) {
            if(check[j]== 1) cnt++;
        }
        if(cnt == n-1) totalCnt++;
    }
    printf("%d" , totalCnt);
    
}
