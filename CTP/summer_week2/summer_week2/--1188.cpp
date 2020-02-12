//
//  1188.cpp
//  summer_week2
//  문제 : 음식평론가
//  https://www.acmicpc.net/problem/1188
//  Created by Hoon on 2018. 7. 10..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

int so,peo,ans;
int each = 1;
int main(){
    scanf("%d %d" , &so,&peo); // so = 3 peo = 4
    while (1) {
        int temp = so*each;
        if(temp%peo == 0) break;
        each++;
    }
    int eachSo = each-1; // eachSo = 3
    int totalSo = so*(eachSo+1);
    //each = 4; 소세지 마다는 3번씩 짜름;
    int tomac = so*(eachSo); // 자르는 횟수tomac = 9
    while (totalSo/peo != 1) {
        tomac =- eachSo-1; // 7 5 3
        totalSo =- eachSo-1;
    }
}

