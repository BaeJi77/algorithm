//  https://www.acmicpc.net/problem/14728
//  14728_벼락치기.cpp
//  summer_week2-2
//
//  Created by Hoon on 2018. 7. 16..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int score[104][10004]; // [0] total time [1] total score
int t_s[104][2]; // [0] time [1] score
int N,Mtime;

void dp(){
    for (int i = 0 ; i < 10004; i++) score[0][i] = 0;
    for (int i = 0 ; i < 104; i++) score[i][0] = 0;
    
    for (int i = 1 ; i <= N; i++) {
        for (int j = 1; j <= Mtime; j++) {
            //사용할경우 사용하지 않을 경우
            //1. 전에꺼를 가지고 와서 나머지를 더할수 있는 경우(현재 사용x)
            //2.기본 것을 무시하고 처음부터 다 비교하는 경우(현재 사용o)
            if(j < t_s[i][0]){
                score[i][j] = score[i-1][j];
            }else{
                int sel = t_s[i][1] + score[i][j-t_s[i][0]];
                int unsel = score[i-1][j];
                score[i][j] = max(sel,unsel);
            }
        }
    }
}

int main(){
    scanf("%d %d" , &N,&Mtime);
    for (int i = 0; i < N; i++) {
        scanf("%d %d" , &t_s[i][0] , &t_s[i][1]);
    }
    dp();
    printf("%d" , score[N][Mtime]);
}


