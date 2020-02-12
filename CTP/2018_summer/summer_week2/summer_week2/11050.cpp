//
//  11050.cpp
//  summer_week2
//  https://www.acmicpc.net/problem/11050
//  Created by Hoon on 2018. 7. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>


using namespace std;

int n,k;
int a=1;
int b=1;
int c=1;
int main(){
    scanf("%d %d", &n,&k);
    for (int i = 1; i <= n; i++) {
        a = a*i;
    }
    for (int i = 1 ; i <= k; i++) {
        b = b*i;
    }
    for (int i = 1 ; i <= n-k; i++) {
        c = c*i;
    }
    printf("%d" , a/(b*c));
    
}

