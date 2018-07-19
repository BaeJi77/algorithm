//  https://www.acmicpc.net/problem/2343
//  2343_기타 레슨.cpp
//  summer_3week-1
//
//  Created by Hoon on 2018. 7. 17..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#define INF 999999999
using namespace std;

int n,m,basicSum,left,right,minn,cnt,maxx,basicMax;
int arr[100004];


int function(){
    left = 1;
    right = 100000000;
    minn = INF;
    while (left <= right) {
        int mid = (left+right)/2;
        cnt = 0;
        int sum = 0;
        for (int i = 0 ; i < n; i++) {
            if(sum + arr[i] > mid){
                cnt++;
                sum=arr[i];
            }else sum += arr[i];
        }

        if(m > cnt){ //bluelay 수가 적게 필요하다 => mid값이 크다
            right = mid -1;
            minn = min(minn , mid);
        }else{ //bluelay 크기의 최소 -> 3.99999 -> 4되기 전까지
            left = mid +1;
//            maxx = max(maxx , mid);
        }
        printf("%d %d %d %d\n" , left , right , mid , cnt);
    }
    return minn;
}

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0 ; i < n; i++) {
        scanf("%d" , &arr[i]);
        basicSum += arr[i];
        basicMax = max(basicMax,arr[i]);
    }

    int ans = function();
    printf("%d" , ans);
}



