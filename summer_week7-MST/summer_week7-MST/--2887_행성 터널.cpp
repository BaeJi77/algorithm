//  https://www.acmicpc.net/problem/2887
//  2887_행성 터널.cpp
//  summer_week7-MST
//
//  Created by Hoon on 2018. 8. 19..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, pair<int, int>>> input; // x, y, z


int main(){
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        int x,y,z;
        scanf("%d %d %d" , &x,&y,&z);
        input.push_back({x,{y,z}});
    }
    
    
}
