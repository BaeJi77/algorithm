//
//  9421.cpp
//  summer_week2
//  https://www.acmicpc.net/problem/9421
//  Created by Hoon on 2018. 7. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <vector>
#include <cstring>


using namespace std;
int def = 1000010;
int arr[1000010];
vector<int> vt;
bool check[500];
int n;
int good,total;

void p(){
    arr[0] = true;
    arr[1] = true;
    for (int i = 2 ; i < sqrt(def); i++) {
        if(arr[i] == true) continue;
        for (int j = i+i; j < def; j+=i) {
            arr[j] = true;
        }
    }

    for (int i = 2; i < def; i++) {
        if(arr[i] == false) vt.push_back(i);
    }
}

int main(){
    p();
    scanf("%d",&n);
    for (int i = 0 ; i < vt.size(); i++) {
        if(vt[i] > n) break;
        memset(check,0,sizeof(check));
        good = vt[i];

        while (1) {
            if(check[good] == true) break;
            total = 0;
            check[good] = true;
            int one = good % 10;
            total = total + one*one;
            good = good / 10;
            while (good != 0) {
                one = good % 10;
                good = good / 10;
                total = total + one*one;
            }
            good = total;
            if(total == 1) {
                printf("%d\n",vt[i]);
                break;
            }
        }
    }

}


