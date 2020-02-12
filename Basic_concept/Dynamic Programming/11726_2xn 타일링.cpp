//  https://www.acmicpc.net/problem/11726
//  11726_2xn 타일링.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 27..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#define MAX 1000
#define mod 10007
typedef long long ll;
using namespace std;

ll N,dp[MAX+4][2]; // [n][0] : 2x1 세로 한칸 , [n][1] : 1x2 세로 두칸

ll sol(ll n, ll status){
    if(n == 0)
        return 1;
    if(n == -1)
        return 0;
    
    ll &ret = dp[n][status];
    if(ret != -1) return ret;
    
    ret = (sol(n-1, 0)%mod);
    ret += (sol(n-2 , 1)%mod);

    return ret;
}

int main(){
    scanf("%lld" , &N);
    for(int i = 0 ; i < MAX+4 ; i++) memset(dp[i],-1,sizeof(dp[i]));
    
    printf("%lld" , ((sol(N-1,0)%mod)+(sol(N-2,1)%mod))%mod);
}
