//  https://www.acmicpc.net/problem/11780
//  11780_플로이드 2.cpp
//  summer_week6_1
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

int n,m;
int dist[104][104];
int via[104][104];

void findPath(vector<int>& vt,int start,int end){
    if(via[start][end] == 0){
        vt.push_back(start);
        vt.push_back(end);
        return;
    }
    int mid = via[start][end];
    
    findPath(vt, start, mid);
    vt.pop_back();
    findPath(vt, mid, end);
}

int main(){
    scanf("%d" , &n);
    scanf("%d" , &m);
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            if(i==j) continue;
            dist[i][j] = INF;
        }
    }
    
    for (int i = 0 ; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d" , &a,&b,&c);
        dist[a][b] = min(dist[a][b],c);
    }
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <= n ; j++) {
            for (int k = 1; k <=n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                    via[j][k] = i;
                }
            }
        }
    }
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            printf("%d " , dist[i][j]);
        }
        puts("");
    }
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            if(dist[i][j] == 0 || dist[i][j] == INF){
                printf("0\n");
            }else{
                vector<int> vt;
                findPath(vt, i, j);
                printf("%d " , vt.size());
                for (int i = 0 ; i < vt.size(); i++) {
                    printf("%d " , vt[i]);
                }
                puts("");
            }
        }
    }
}
