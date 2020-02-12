//  https://www.acmicpc.net/problem/14890
//  14890_경사로.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 9. 3..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int N,L,map[104][104],cnt;

int main(){
    scanf("%d %d" , &N,&L);
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    
    //가로
    for (int i = 0; i < N; i++) {
        bool flag = true;
        int temp = 0;
        int preValue = map[i][0];
        int nowRoad = 0;
        for (int j = 0 ; j < N; j++) {
            nowRoad = map[i][j];
            if(preValue == nowRoad){
                temp++;
            }else if(preValue < nowRoad){
                if(temp >= L){
                    temp = 0;
                }else{
                    flag = false;
                }
            }else if(preValue > nowRoad){
                if(j+L > N){
                    flag = false;
                }else{
                    for (int  k = j+1; k <= j+L; k++) {
                        if(map[i][k] != nowRoad)
                            flag = false;
                    }
                }
            }
        }
    }
}
