#include <cstdio>
#include <cstring>

using namespace std;


const int mod = 10007;
int N;
int cache[10][1000];

int func(int cur, int digit){
    if(digit == N)
        return 1;

    int& ret = cache[cur][digit];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i = 0 ; i <= 9 ; i++){
        if(i >= cur)
            ret += func(i, digit+1)%mod;
    }

    return ret%mod;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    memset(cache,-1,sizeof(cache));
    printf("%d\n" , func(0,0));
}