//
//  11659.cpp
//  summer_week2
//  부분합 구하기
//  https://www.acmicpc.net/problem/11659
//  Created by Hoon on 2018. 7. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int n,m,tempsum,input;
int sum[100010];
int a,b;
int main(int argc, const char * argv[]) {
    scanf("%d %d" , &n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&input);
        tempsum += input;
        sum[i] = tempsum;
    }
    
    while (m--) {
        scanf("%d %d" , &a,&b);
        printf("%d\n" , sum[b] - sum[a-1]);
    }
}

