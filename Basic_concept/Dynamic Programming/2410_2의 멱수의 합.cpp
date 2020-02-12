#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 1000000;
const int MOD = 1e9;

int N;
int cache[MAX+4][21];

int pow2(int a, int b) { 
    int pow = 1; 
    while (b) 
    { 
        if (b & 1) 
        { 
            pow = pow * a; 
            --b; 
        } 
        a = a*a; 
        b = b/2; 
    } 
    return pow; 
}

int func(int number, int power){ // number에서 0으로 갈때 2의 지수가 power일때 경우의 수
    if(number == 0)
        return 1;

    int& ret = cache[number][power];
    if(ret != -1)
        return ret;

    ret = 0;
    int temp = power;
    for(int i = temp ; i >= 0 ; i--){
        int nowNumber = pow2(2, i);
        if(number - nowNumber < 0)
            continue;
        ret = ( ret + func(number - nowNumber, i) % MOD) % MOD;
    }
    return ret % MOD;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    memset(cache,-1,sizeof(cache));
    printf("%d\n", func(N, 20) % MOD);
}