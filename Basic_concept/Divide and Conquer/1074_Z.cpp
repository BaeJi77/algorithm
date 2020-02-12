//  https://www.acmicpc.net/problem/1074
//  1074_Z.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long ll;

int range[20] = {1};
int rr,cc,Number;
bool ended;

ll power(ll val,ll vpow){
    if(vpow == 0) return 1;
    if(vpow % 2 == 1) return val*power(val,vpow-1);
    else return power(val*val,vpow/2);
}

//void solve(ll y,ll x,ll n){
//    if(ended) return;
//    if(n == 1){
//        for (ll i = y; i < y+2; i++) {
//            for (ll j = x; j < x+2; j++) {
//                z[i][j] =Number;
//                if(i==r && j==c) {
//                    printf("%lld" , Number);
//                    ended = true;
//                    return;
//                }
//                Number++;
//            }
//        }
//    }else{
//        solve(y, x, n-1);mi
//        solve(y, x + power(2,n-1), n-1);
//        solve(y + power(2,n-1), x, n-1);
//        solve(y + power(2,n-1), x + power(2,n-1), n-1);
//    }
//}

int solve(int y,int x, int n){
    if(n==0)
        return 1;
    
    //위쪽편
    if(y < range[n-1]){
        //왼쪽
        if(x < range[n-1]) {
            return solve(y, x, n-1);
        }
        //오른쪽
        else{
            return range[n-1]*range[n-1] + solve(y, x-range[n-1], n-1);
        }
    //아래쪽
    }else{
        //왼쪽
        if(x < range[n-1]) {
            return range[n-1]*range[n-1]*2 + solve(y-range[n-1], x, n-1);
        }
        //오른쪽
        else {
            return range[n-1]*range[n-1]*3 + solve(y-range[n-1], x-range[n-1], n-1);
        }
    }
}

int main(){
    scanf("%d %d %d" , &Number,&rr,&cc);
    for (int i = 1; i <= 15; i++) {
        range[i] = 2*range[i-1];
    }
    
    printf("%d\n" , solve(rr,cc,Number)-1);
}
