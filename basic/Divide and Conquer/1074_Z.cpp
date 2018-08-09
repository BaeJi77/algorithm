//  https://www.acmicpc.net/problem/1074
//  1074_Z.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cmath>
using namespace std;
int N,r,c,Number;
int z[33000][33000];

void solve(int y,int x,int n){
    if(n == 1){
        for (int i = y; i < y+2; i++) {
            for (int j = x; j < x+2; j++) {
                z[i][j] =Number;
                if(i==r && j==c) {
                    printf("%d" , Number);
                    return;
                }
                Number++;
            }
        }
    }else{
        solve(y, x, n-1);
        solve(y, x + pow((double)2,(double)n-1), n-1);
        solve(y + pow((double)2,(double)n-1), x, n-1);
        solve(y + pow((double)2, (double)n-1), x + pow((double)2, (double)n-1), n-1);
    }
}

int main(){
    scanf("%d %d %d" , &N,&r,&c);
    solve(0,0,N);
//    printf("%d" , z[r][c]);
}
