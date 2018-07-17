//
//  6236_용돈 관리.cpp
//  summer_3week-1
//  https://www.acmicpc.net/problem/6236
//  Created by Hoon on 2018. 7. 17..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int n,m,left,right,total;
int arr[100004];

void function(){
    left = 1;
    right = 10000;
    while (left<=right) {
        int mid = (left+right)/2;
        //값을 두개와 비교 1. 새로운 값의 인출횟수를 곱한것은 필요한 돈의 총합을 넘어야한다. 2. 1번에서 구한 평균값은 맥스값보다 크거나 같아야 한다.
        int tmepProduct = mid * m;
    }
}

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0 ; i < n; i++) {
        scanf("%d" , &arr[i]);
        total += arr[i];
    }
    
    function();
}
