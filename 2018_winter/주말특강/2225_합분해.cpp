#include <cstdio>
#include <cstring>

typedef long long ll;
using namespace std;

const int mod = 1e9;

ll N,K;
ll cache[204][204]; // func(sum, count) 현재 sum을 count의 수를 이용해서 만듬

ll solve(ll sum, ll count){
	if(count == K){
		return sum == N ? 1 : 0;
	} 
	
	ll& ret = cache[sum][count];
	if(ret != -1)
		return ret;
	
	ret = 0;
	for(ll i = 0 ; i <= N ; i++){
		if(sum + i <= N)
			ret += solve(sum + i, count + 1)%mod;
	}
	
	return ret%mod;
}


int main(){
	freopen("input.txt","r",stdin);
	scanf("%lld %lld" , &N,&K);
	memset(cache, -1, sizeof(cache));
	printf("%lld\n", solve(0,0)%mod);
}