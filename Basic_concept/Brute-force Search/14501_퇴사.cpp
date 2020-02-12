//  https://www.acmicpc.net/problem/14501
//  14501_퇴사.cpp
//  basic
//
//  Created by Hoon on 2018. 9. 3..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N,dp[20][15004];
vector<pair<int, int>> vt;

int sol(int pos, int money){
    if(pos == N)
        return 0;
    
    int &ret = dp[pos][money];
    if(ret != -1)
        return -1;
    
    //상담을 하지 않고 지나감
    ret = sol(pos+1, money);
    if(pos + vt[pos].first <= N){
        ret = max(ret, sol(pos+vt[pos].first , money + vt[pos].second) + vt[pos].second);
    }
    
    return ret;
}

int main(){
    scanf("%d" , &N);
    for(int i = 0; i < N ; i++){
        int a,b;
        scanf("%d %d" , &a,&b);
        vt.push_back({a,b});
    }
    memset(dp,-1,sizeof(dp));
    
    printf("%d" , sol(0,0));
}
