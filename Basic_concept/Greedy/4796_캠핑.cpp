//  https://www.acmicpc.net/problem/4796
//  4796_캠핑.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int l,p,v,ans,outNumber;

int main(){
    while(scanf("%d %d %d" , &l,&p,&v)){
        if(l==0 && p==0 && v==0) break;
        ans = 0;
        
        int product = v/p;
        
        v = v%p; // 남은 일
        
        ans = l*product;
        if(v > l){
            ans += l;
        }else{
            ans += v;
        }
        
        outNumber++;
        printf("Case %d: %d\n" , outNumber , ans);
    }
}
