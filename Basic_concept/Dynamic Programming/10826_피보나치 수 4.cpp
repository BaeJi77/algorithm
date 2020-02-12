#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int N;
ll cache[10001];

ll func(int n){
    if(n <= 1)
        return n;
    
    ll& ret = cache[n];
    if(ret != -1)
        return ret;
    ret = func(n-1) + func(n-2);
    // printf("%lld %d\n", ret, n);
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    memset(cache,-1,sizeof(cache));
    printf("%lld", func(N));
}