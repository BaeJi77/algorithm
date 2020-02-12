#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll N,L,R;
ll cache[104][104][104]; 

// 높은 빌딩부터 세운다고 과정
/*
1. 큰 건물 사이로 들어라 보이지 않음
2. 왼쪽에서 봤을때 하나의 건물이 더 보이는 경우
3. 오른쪽에서 봤을때 하나의 건물이 더 보이는 경우
*/
ll func(ll idx, ll l, ll r){
    if(idx == 1 && l == L && r == R)
        return 1;
    else if(idx == 1){
        return 0;
    }
    
    ll& ret = cache[idx][l][r];
    if(ret != -1)   
        return ret;
    
    ret = func(idx-1, l, r) * (idx - 2) % MOD;
    if(l < L){
        ret += func(idx - 1, l+1, r) % MOD;
    }
    if(r < R){
        ret += func(idx - 1, l, r+1) % MOD;
    }

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%lld %lld %lld", &N, &L, &R);
    memset(cache,-1,sizeof(cache));
    printf("%lld", func(N, 1, 1) % MOD);
}