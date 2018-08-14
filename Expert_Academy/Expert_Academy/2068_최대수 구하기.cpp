//  https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QQhbqA4QDFAUq&categoryId=AV5QQhbqA4QDFAUq&categoryType=CODE
//  2068_최대수 구하기.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 8. 13..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int test,outNumber;
    outNumber = 0;
    scanf("%d" , &test);
    while (test--) {
        int maxx=0;
        outNumber++;
        for (int i = 0; i < 10; i++) {
            int a;
            scanf("%d" , &a);
            maxx = max(maxx,a);
        }
        printf("#%d %d\n" , outNumber , maxx );
    }
}
