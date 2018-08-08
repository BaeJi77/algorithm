//  https://www.acmicpc.net/problem/8393
//  8393_합.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>

int n,sum;

int main(int argc, const char * argv[]) {
    //시간 복잡도 n -> O(n)
    scanf("%d" , &n);
    for (int i = 1; i <=n; i++) {
        sum += i;
    }
    printf("%d" , sum);
    
    //시간 복잡도 상수 -> O(1)
    scanf("%d" , &n);
    sum = n*(n+1)/2;
    printf("%d" , sum);
}
