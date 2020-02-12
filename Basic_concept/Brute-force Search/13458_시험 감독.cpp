//  https://www.acmicpc.net/problem/13458
//  13458_시험 감독.cpp
//  basic
//
//  Created by Hoon on 2018. 9. 3..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

#define MAX 1000000
using namespace std;
typedef long long ll;

ll N,arr[MAX+4],B,C,cnt;

int main(){
    scanf("%lld" , &N);
    for (ll i = 0; i < N; i++) {
        scanf("%lld" , &arr[i]);
    }
    scanf("%lld %lld" , &B,&C);
    
    for (ll i = 0; i < N; i++) {
        arr[i] -= B;
        cnt++;
        if(arr[i] > 0){
            if(arr[i] % C == 0){
                cnt += arr[i] / C;
            }else{
                cnt += arr[i]/C +1;
            }
        }
        
    }
    
    printf("%lld" , cnt);
}
