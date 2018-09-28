//  https://www.acmicpc.net/problem/12893
//  DisjointSet_12893.cpp
//  2학기
//
//  Created by Hoon on 2018. 9. 28..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>

#define MAX 2000
using namespace std;

int N,M,p[MAX+4];

int ffind(int x){
    if(p[x] < 0) return x;
    return p[x] = ffind(p[x]);
}

int Merge(int a,int b){
    int aa = ffind(a);
    int bb = ffind(b);
    if(aa == bb)
        return -1;
    p[aa] = bb;
    return 1;
}

void init(){
    memset(p,-1,sizeof(p));
}

int main(){
    scanf("%d %d", &N,&M);
    init();
    for (int i = 0; i <M; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        Merge(a, b);
    }
    
    bool result = false;
    for (int i = 1; i <= N-1; i++) {
        if(ffind(i) != ffind(i+1))
            result = true;
    }
    
    if(result == false)
        printf("0");
    else
        printf("1");
}
