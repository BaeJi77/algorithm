//
//  10871_x보다 작은 수.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 8..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int n,m;

int main(){
    scanf("%d %d" , &n,&m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d" , &k);
        if(m > k) printf("%d " , k);
    }
}
