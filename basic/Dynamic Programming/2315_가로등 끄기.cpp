#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f;

ll N,M;
ll cost,minx,maxx;
pair<ll, ll> light[1001];
bool visited[1001];
ll cache[1001][1001][2];
ll psum[1001];

ll func(ll l, ll r, ll now){
    if(l ==  minx && r == maxx){
        return 0; // 현재 값을 리턴해줘야되는지 생각
    }

    ll& ret = cache[l][r][now];
    if(ret != -1)
        return ret;

    ll nowCost = 0;
    if(l != 0)
        nowCost = cost - ( psum[r] - psum[l - 1] );
    else
        nowCost = cost - psum[r];

    ret = INF;
    //now : 0 == 왼, 1 == 오
    if(l - 1 >= minx){
        ll goLeftDistance = now == 0 ? 1 : r - l + 1;
        ret = min(ret, func(l - 1, r, 0) + goLeftDistance * nowCost);
    }
    if(r + 1 <= maxx){
        ll goRightDistance = now == 1 ? 1 : r - l + 1;
        ret = min(ret, func(l, r + 1, 1) + goRightDistance * nowCost);
    }

    return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    memset(cache,-1,sizeof(cache));
    minx = INF;
    maxx = -INF;
    ll sx;
    for(ll i = 1 ; i <= N ; i++){
        ll a,b;
        scanf("%d %d", &a, &b);
        minx = min(minx, a);
        maxx = max(maxx, a);
        cost += b;
        light[i] = make_pair(a,b);
        if(i == M)
            sx = a;
    } 
    
    for(int i = 1; i <= N ; i++){
        ll x = light[i].first;
        ll ncost = light[i].second;
        for(int j = x ; j <= maxx ; j++)
            psum[j] += ncost;
    }
    printf("%lld", func(sx, sx, 0));
}