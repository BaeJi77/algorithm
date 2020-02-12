//  https://www.acmicpc.net/problem/1774
//  1774_우주신과의 교감.cpp
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

int n,m,p[1004],cnt;
double sum;
pair<int, int> arr[1004];
vector<pair<double, pair<int, int>>> vt;

void init(){
    for (int i = 0; i <=n; i++) {
        p[i] = i;
    }
}

int Find(int x){
    if(p[x] == x)return x;
    return p[x] = Find(p[x]);
}

bool Merge(int u, int v){
    int uu = Find(u);
    int vv = Find(v);
    if(uu == vv) return false;
    p[vv] = uu;
    return true;
}

int main(){
    scanf("%d %d" , &n,&m);
    init();
    for (int  i = 1; i <= n; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        arr[i] = make_pair(a, b);
    }
    
    for (int i = 0 ; i < m; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        if(Find(a)==Find(b)) continue;
        Merge(a, b);
        cnt++;
    }
  
    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j<=n; j++) {
            double w = sqrt(pow(arr[i].first - arr[j].first,2)+ pow(arr[i].second - arr[j].second,2));
            vt.push_back({w,{i,j}});
        }
    }
    sort(vt.begin(),vt.end());
    
    for (int i = 0; i < vt.size(); i++) {
        if(cnt == n-1) break;
        double w = vt[i].first;
        int a = vt[i].second.first;
        int b = vt[i].second.second;
        
        if(Find(a) == Find(b)) continue;
        Merge(a, b);
        cnt++;
        sum += w;
    }
    printf("%.2lf" , sum);
}
