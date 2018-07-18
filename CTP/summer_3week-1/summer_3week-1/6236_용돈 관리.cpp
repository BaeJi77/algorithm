//
//  6236_용돈 관리.cpp
//  summer_3week-1
//  https://www.acmicpc.net/problem/6236
//  Created by Hoon on 2018. 7. 17..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <limits.h>
#define INF INT_MAX
using namespace std;

int n,m,left,right,basicTotal,basicMax,maxx,cnt,minn;
int arr[100004];

int function(){
    left = 1;
    right = 1000000000;
    while (left <= right) {
        int mid = (left+right)/2;
        cnt = 0;
        int sum = 0;
        for (int i = 0 ; i < n; i++) {
            if(sum + arr[i] > mid){
                sum = arr[i];
                cnt++;
            }else sum += arr[i];
        }

        if(m > cnt){ //돈을 적게 뽑아도 된다 => mid값이 크다. => mid값을 줄이자.
            right = mid -1;
        }else { // mid 값을 키우자 // 3.99999 -> 4가 될정도로 가까이 mid가 커지길 원해
            left = mid +1;
            maxx = max(maxx , mid);
        }
//        printf("%d %d %d\n" , left , right , mid);
    }

    return maxx;
}

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0 ; i < n; i++) {
        scanf("%d" , &arr[i]);
        basicTotal += arr[i];
        basicMax = max(basicMax,arr[i]);
    }

    int ans = function();
    if(basicMax > ans) printf("%d" , basicMax);
    else printf("%d" , ans+1);
}



