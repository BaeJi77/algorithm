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
int each =1;
int main(){
    scanf("%d %d" , &so,&peo);
    while (1) {
        int temp = so*each;
        if(temp%peo == 0) break;
        each++;
    }
    printf("%d" , so*(each-1));
}
