//
//  13701.cpp 중복제거
//  https://www.acmicpc.net/problem/13701
//  summer_week1-2
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
int a[1100000];
int input;
int arr, pos;

int main(){
    while (scanf("%d",&input) != EOF) {
        arr = input/32;
        pos = input%32;
        int print = a[arr]&(1<<pos);
        a[arr] |= (1<<pos);
        if(print == 0) printf("%d " , input);
    }
}

