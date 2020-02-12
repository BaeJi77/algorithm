//  https://www.acmicpc.net/problem/1449
//  1449_수리공 항승.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,l,ended;
int pipe[1004];
vector<int> vt;
int main(){
    scanf("%d %d" , &n,&l);
    for (int i = 0 ; i < n ; i++) {
        int position = 0;
        scanf("%d" , &position);
        vt.push_back(position);
    }
    
    sort(vt.begin(),vt.end());
    
    for (int i = 0 ; i < vt.size(); i++) {
        int position = vt[i];
        if(pipe[position] == 0){
            ended++;
            int now = position;
            for (int  k = now; k < now + l; k++) {
                pipe[k] = ended;
            }
        }
    }
    
    printf("%d" , ended);
}
