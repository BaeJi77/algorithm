#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

ll N,cache[1000004];

ll func(ll index){
    if(index == N-1)
        return 1;
    if(index > N-1)
        return 0;
    
    ll& ret = cache[index];
    if(ret != -1)
        return ret;
    
    ret = 0;
    ret = func(index+1) + func(index+2);

    return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    memset(cache,-1,sizeof(cache));
    printf("%lld" , func(0));
}