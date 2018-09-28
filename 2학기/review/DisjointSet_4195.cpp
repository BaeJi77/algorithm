//  https://www.acmicpc.net/problem/4195
//  DisjointSet_4195.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int p[200004];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int Merge(int a,int b){
    int aa = find(a);
    int bb = find(b);
    
    if(aa==bb)
        return -p[aa];
    p[aa] += p[bb];
    p[bb] = aa;
    return -p[aa];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int test;
    scanf("%d ", &test);
    while (test--) {
        int N;
        scanf("%d" , &N);
        memset(p,-1,sizeof(p));
        map<string,int> mp;
        
        int idx = 0;
        for (int i = 0; i < N; i++) {
            char st1[25],st2[25];
            int n1,n2;
            scanf("%s %s", &st1,&st2);
            if(mp.count(st1) == 0)
                mp[st1] = idx++;
            n1 = mp[st1];
            if(mp.count(st2) == 0)
                mp[st2] = idx++;
            n2 = mp[st2];
            
            printf("%d\n" , Merge(n1,n2));
        }
    }
}
