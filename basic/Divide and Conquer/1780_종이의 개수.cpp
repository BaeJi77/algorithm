//  https://www.acmicpc.net/problem/1780
//  1780_종이의 개수.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int N;
int result[3];
int paper[3004][3004];

void solve(int y, int x,int n){
    if(n==1) result[paper[y][x]+1]++;
    else{
        int base = paper[y][x];
        bool check = true;
        for (int i = y; i < y+n; i++) {
            for (int j = x; j < x+n; j++) {
                if(base != paper[i][j]) {
                    check = false;
                    break;
                }
                if(check == false) break;
            }
        }
        
        if(check == true) result[paper[y][x]+1]++;
        else{
            int nn = n/3;
            for (int i = y; i < y+n; i+=nn) {
                for (int j = x; j < x+n; j+=nn) {
                    solve(i, j, nn);
                }
            }
        }
    }
}


int main(){
    scanf("%d" , &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d" , &paper[i][j]);
        }
    }
    solve(0,0,N);
    for (int i = 0 ; i< 3; i++) {
        printf("%d\n" , result[i]);
    }
}
