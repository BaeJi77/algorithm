//  https://www.acmicpc.net/problem/2660
//  2660_회장 뽑기.cpp
//  summer_week6_1
//
//  Created by Hoon on 2018. 8. 6..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int n,a,b,minn,basic;
int dist[54][54];
vector<int> vt;

int main(){
    scanf("%d" , &n);
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i==j) continue;
            dist[i][j] = INF;
        }
    }
    
    while (scanf("%d %d" , &a,&b)) {
        if(a == -1 && b== -1) break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    
    minn = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    
    basic = INF;
    for (int i = 1; i<=n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            temp = max(dist[i][j] , temp);
        }
        basic = min(temp,basic);
    }
    
    for (int i = 1; i <= n; i++) {
        int temp = -1;
        for (int j = 1; j <= n; j++) {
            if(i==j) continue;
            temp = max(dist[i][j] , temp);
        }
        if(temp == basic) vt.push_back(i);
    }
    
    sort(vt.begin(), vt.end());
    
    printf("%d %d\n" , basic , vt.size());
    for (int i = 0; i < vt.size(); i++) {
        printf("%d " , vt[i]);
    }
}

