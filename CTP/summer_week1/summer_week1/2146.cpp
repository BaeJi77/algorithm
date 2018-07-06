//
//  2146.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n,mmax,cnt,tcnt;
int map[110][110];


//같은 번호를 주고 같은 번호끼리는 신경안쓰고 max를 한번 찾아보자
int main(){
    scanf("%d" , &n);
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    
    
}
