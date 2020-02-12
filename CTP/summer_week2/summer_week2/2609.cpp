//
//  2609.cpp
//  summer_week2
//  https://www.acmicpc.net/problem/2609
//  최대공약수와 최소공배수
//  유클리드
//  Created by Hoon on 2018. 7. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
int n,m;

void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}

int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

int main(){
    scanf("%d %d" , &n,&m);
    if(m>n) swap(n,m);
    int gcd = GCD(n,m);
    printf("%d\n",gcd);
    int lcm = n*m/gcd;
    printf("%d",lcm);
}


