//  https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QQ6qqA40DFAUq&categoryId=AV5QQ6qqA40DFAUq&categoryType=CODE
//  2070_큰 놈, 작은 놈, 같은 놈.cpp
//  Expert_Academy
//
//  Created by Hoon on 2018. 8. 13..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int main(){
    int test,outNumber;
    outNumber = 0;
    scanf("%d" , &test);
    while (test--) {
        outNumber++;
        int a,b;
        scanf("%d %d",&a,&b);
        if(a > b){
            printf("#%d >\n" , outNumber);
        }else if(a==b){
            printf("#%d =\n" , outNumber);
        }else{
            printf("#%d <\n" , outNumber);
        }
    }
}
