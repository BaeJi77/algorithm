//  https://www.acmicpc.net/problem/1946
//  1946_신입 사원.cpp
//  summer_week4-1
//
//  Created by Hoon on 2018. 7. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int T,n,cnt,ended;
vector<pair<int, int>> vt;
int arr[100100];
int main(){
    scanf("%d" ,&T);
    while (T--) {
        vt.clear();
        cnt = 1;
        scanf("%d" , &n);
        for (int i = 0; i < n; i++) {
            int a,b;
            scanf("%d %d", &a , &b);
            arr[a] = b;
            vt.push_back({a,b});
        }
        sort(vt.begin(), vt.end());
        
        //vector <pair> 방식
//        ended = vt[0].second;
//        for (int i = 1; i < n; i++) {
//            int nowScore = vt[i].second;
//            if(ended > nowScore){
//                cnt++;
//                ended = nowScore;
//            }
//            if(ended == 1) break;
//        }
        
        //array 방식
        ended = arr[1];
        for (int i = 2; i <= n; i++) {
            if(ended > arr[i]){
                cnt++;
                ended = arr[i];
            }
            if(ended == 1) break;
        }

        printf("%d\n" , cnt);
    }
}


