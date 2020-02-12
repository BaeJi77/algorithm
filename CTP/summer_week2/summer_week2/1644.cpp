//
//  1644.cpp
//  summer_week2
//  https://www.acmicpc.net/problem/1644
//  소수의 연속합
//  Created by Hoon on 2018. 7. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int n; // 1 ≤ N ≤ 4,000,000
int arr[4000010];
int def = 4000010;
vector<int> vt;
int cnt,l,r,sum;

void p(){
    for (int i = 2; i < sqrt(4000010) ; i++) {
        if(arr[i] == true) continue;
        for (int j = i+i; j < def ; j+=i) {
            arr[j] = true;
        }
    }
    for (int i = 2; i < def; i++) {
        if(arr[i] == false) {
            vt.push_back(i);
        }
    }
}

int main(){
    p();
    scanf("%d",&n);
    sum = vt[0];
    while (r<vt.size()) {
        if(sum <= n){
            r++;
            if(sum == n) cnt++;
            sum += vt[r];
        }else if(sum > n){
            sum -= vt[l];
            l++;
            if(l > r) {
                r = l;
                sum = sum+vt[r];
            }
            
        }
    }
    printf("%d" , cnt);
}


