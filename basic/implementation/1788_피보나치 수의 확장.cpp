#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int MOD = 1e9;

int N;
int cache[MAX+4], cache2[MAX+4];

int func(int n){
    if(n == 0)
        return 0;
    if(n == 1)  
        return 1;
    
    int& ret = cache[n];
    if(ret != -1)
        return ret;
    
    return ret = (func(n-1) % MOD + func(n-2) % MOD )% MOD;
}

int func2(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    int& ret = cache2[n];
    if(ret != -1)
        return ret;
    
    ret = (func2(n-2) % MOD - func2(n-1) % MOD)% MOD;
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    memset(cache,-1,sizeof(cache));
    memset(cache2,-1,sizeof(cache2));
    if(N == 0)
        printf("0\n0");
    else if(N > 0){
        printf("1\n");
        printf("%d", func(N));
    } else {
        int ans = func2(abs(N));
        printf("%d\n", ans > 0 ? 1 : -1);
        printf("%d", abs(ans));
    }
}