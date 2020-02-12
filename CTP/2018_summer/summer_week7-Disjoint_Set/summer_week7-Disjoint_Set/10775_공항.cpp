//  https://www.acmicpc.net/problem/10775
//  10775_공항.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int G,P,cnt;
int p[1000004];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void init(){
    for (int i = 1; i<=G; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d" , &G);
    scanf("%d" , &P);
    init();
    while (P--) {
        int a;
        scanf("%d" , &a);
        if(find(a) == 0) break;
        else{
            cnt++;
            p[find(a)] = find(a)-1;
        }
    }
    
    printf("%d" , cnt);
}
