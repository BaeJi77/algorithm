#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

ll N, map[104][104];
ll cache[104][104];

ll func(ll y, ll x){
    if(y == N && x == N)
        return 1;
    if(y > N || x > N)
        return 0;
    
    ll& ret = cache[y][x];
    if(ret != -1)
        return ret;
    
    ret = 0;    
    ret = func(y+map[y][x],x) + func(y, x+map[y][x]);

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    for(ll i = 1 ; i <= N ; i++){
        for(ll j = 1 ; j <= N ; j++){
            scanf("%d" , &map[i][j]);
        }
    }

    memset(cache,-1,sizeof(cache));
    printf("%lld" , func(1,1));
}