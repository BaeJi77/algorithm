//
//  2405.cpp
//  summer_week2
//  제목 : 세 수 , 두 M
//  https://www.acmicpc.net/problem/2405
//  Created by Hoon on 2018. 7. 10..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> vt;
int N;
double MAXX;
int arr[100010];

void select(vector<int>& go, int dept){
    if (go.size()==3) {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += go[i];
        }
        double temp = abs(total - go[1]*3);
        if(MAXX < temp){
            MAXX = max(MAXX , temp);
//            for (int i = 0; i < 3; i++) {
//                printf("%d " , go[i]);
//            }
//            puts("");
        }
        return;
    }
    if(dept >= N) return;
    go.push_back(vt[dept]);
    select(go, dept+1);
    go.pop_back();
    select(go, dept+1);
}

int main(){
    scanf("%d" , &N);
    for (int i = 0 ; i < N ; i++) {
        int input = 0;
        scanf("%input" , &input);
        vt.push_back(input);
    }
    sort(vt.begin(),vt.end());
    vector<int> newVector;
    select(newVector, 0);
    int a = MAXX;
    printf("%d" , a);
}

