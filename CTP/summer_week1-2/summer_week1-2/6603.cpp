//
//  6603.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

vector<int> total;
int t,size;

void loopNum(vector<int> vt , int pos){
    if(vt.size() == 6){
        for (int i = 0; i < 6; i++) printf("%d " , vt[i]);
        puts("");
        return;
    }
    if(pos >= t) return;
    vt.push_back(total[pos]);
    loopNum(vt, pos+1);
    vt.pop_back();
    loopNum(vt, pos+1);
}

int main(){
    while (scanf("%d",&t)) {
        if(t == 0) break;
        total.clear();
        for(int i = 0 ; i < t ; i++){
            int k =0;
            scanf("%d" , &k);
            total.push_back(k);
        }
        size = total.size();
        vector<int> emptyvector;
        loopNum(emptyvector , 0);
        puts("");
    }
}

