//
//  1700_멀티탭 스케쥴링.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <climits>
using namespace std;

int n,k,ans;
int order[104];
vector<int> vt;

int mostLater(int base , int number){
    int cnt = 0;
    for (int i = base; i < k; i++) {
        if(order[i] == number) return cnt;
        cnt++;
    }
    return cnt;
}


int main(){
    scanf("%d %d" , &n,&k);
    for (int i = 0; i < k; i++) {
        int a;
        scanf("%d" , &a);
        order[i] = a;
    }
    
    for (int i = 0; i < k; i++) {
        bool continueVar = false;
        bool changeVar = false;
        int now = order[i];
        int maxCnt = 0;
        int target = 0;
        if(vt.size() != n){
            bool sameData = false;
            for (int j = 0; j < vt.size(); j++) {
                if(now == vt[j]) sameData = true;
            }
            if(sameData == false)vt.push_back(now);
        }else{ // vt.size() == n
            for (int j = 0; j < vt.size(); j++) {
                int tempCnt = mostLater(i,vt[j]);
                if(tempCnt < n) {
                    continueVar = true;
                }else{
                    if(maxCnt < tempCnt){
                        maxCnt = tempCnt;
                        target = j;
                        changeVar = true;
                    }
                }
            }
            if(continueVar == true && changeVar == false) continue;
            else {
                vt[target] = now;
                printf("%d %d %d\n" , i,target , vt[target]);
                ans++;
            }
        }
    }
    
    printf("%d" , ans);
}
