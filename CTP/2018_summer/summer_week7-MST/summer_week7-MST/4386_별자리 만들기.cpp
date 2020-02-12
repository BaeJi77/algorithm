//  https://www.acmicpc.net/problem/4386
//  4386_별자리 만들기.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n,p[104];
double sum;
vector<pair<double, double>> input;
vector<pair<double, pair<int, int>>> vt;

void init(){
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}

bool Merge(int u , int v){
    int uu = Find(u);
    int vv = Find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}

int main(){
    scanf("%d" , &n);
    init();
    for (int i = 0; i < n; i++) {
        double a,b;
        scanf("%lf %lf" , &a,&b);
        input.push_back({a,b});
    }
    
    int cnt = 0;
    for (int i = 0 ; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double w = sqrt(pow(input[i].first-input[j].first,2) + pow(input[i].second - input[j].second,2));
//            printf("%lf %d %d\n" , w , i , j);
            vt.push_back({w,{i,j}});
            cnt++;
        }
    }
    
    sort(vt.begin(),vt.end());
    
    int totalCnt = 0;
    for (int i = 0; i < cnt; i++) {
//        if(totalCnt == n-1) break;
        double w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a) == Find(b)) continue;
        Merge(a, b);
        sum += w;
        totalCnt++;
    }
    
    printf("%.2lf" , sum);
}
