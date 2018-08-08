//
//  1018_체스판 다시 칠하기.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <climits>
using namespace std;

int n,m,minn;
char map[54][54];

int findMin(int y,int x){
    int cnt = 0;;
    if(map[y][x] == 'B'){
        //처음이 블랙인경우
        for (int i = y; i < y+8; i++) {
            for (int j = x; j < x+8; j++) {
                if(i%2 == 0){//짝수줄
                    if(j%2 == 0){
                        //세로 : 짝수 가로 : 짝수
                        if(map[i][j] == 'W') cnt++;
                    }else{
                        if(map[i][j] == 'B') cnt++;
                    }
                }else{ // 세로 : 홀수
                    if(j%2 == 0){
                        if(map[i][j] == 'B') cnt++;
                    }else{
                        if(map[i][j] == 'W') cnt++;
                    }
                }
            }
        }
    }else{
        for (int i = y; i < y+8; i++) {
            for (int j = x; j < x+8; j++) {
                if(i%2 == 0){
                    if(j%2 == 0){
                        if(map[i][j] == 'B') cnt++;
                    }else{
                        if(map[i][j] == 'W') cnt++;
                    }
                }else{
                    if(j%2 == 0){
                        if(map[i][j] == 'W') cnt++;
                    }else{
                        if(map[i][j] == 'B') cnt++;
                    }
                }
            }
        }
    }
    cnt =  min(cnt,64-cnt);
    return cnt;
}

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c" , &map[i][j]);
        }
    }

    minn = INT_MAX;
    for (int i = 0; i <= n-8; i++) {
        for (int j = 0; j <= m-8; j++) {
            int tempMin = findMin(i,j);
            minn = min(minn , tempMin);
        }
    }
    printf("%d" , minn);
}
