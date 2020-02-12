//  https://www.acmicpc.net/problem/2217
//  2217_로프.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n,minn,maxx;
vector<int> vt;

int main(){
    minn = INT_MAX;
    scanf("%d" , &n);
    for (int i = 0 ; i < n; i++) {
        int a;
        scanf("%d" , &a);
        vt.push_back(a);
    }
    
    sort(vt.begin(),vt.end());
    
    int cnt = 0;
    for (int i = vt.size()-1; i >= 0; i--) {
        cnt++;
        maxx= max(maxx,vt[i]*cnt);
    }
    
    
    printf("%d" , maxx);
}
