//
//  2352_반도체 설계.cpp
//  summer_week4-1
//
//  Created by Hoon on 2018. 7. 25..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n,lastIndex;
vector<pair<int, int>> vt;
vector<int> vvt;
vector<int> temp;
vector<int> LIS;

int main(){
    scanf("%d" , &n);
    for (int i = 1; i <= n; i++) {
        int value = 0;
        scanf("%d" , &value);
        vt.push_back({value,i});
        vvt.push_back(value);
    }
    
    
    temp.push_back(vvt[0]);
    for (int i = 1; i < n; i++) {
        if(temp.back() >= vvt[i]){
            int index = lower_bound(temp.begin(),temp.end(),vvt[i]) - temp.begin();
            temp[index] = vvt[i];
        }else{
            temp.push_back(vvt[i]);
        }
    }
    
    sort(vt.begin(),vt.end());
    
    lastIndex = vt[0].second;
    LIS.push_back(lastIndex);
    for (int i = 1; i < n; i++) {
        int nowIndex = vt[i].second;
        if(LIS.back() >= nowIndex) {
            LIS.pop_back();
            LIS.push_back(nowIndex);
        }else{
            LIS.push_back(nowIndex);
        }
    }
    
//    printf("%d\n" , LIS.size());
    
    printf("%d" , temp.size());
}
