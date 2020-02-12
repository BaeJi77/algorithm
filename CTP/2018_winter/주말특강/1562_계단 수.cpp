#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int N;
const int mod = 1e9;
int cache[101][10][1 << 10]; //현재 n에 자릿수에서 이 비트가 켜져 있는 상태에 계단 수




int func(int idx, int cur, int state) {
	if (idx == N - 1) {
		return state == (1 << 10) - 1 ? 1 : 0;
	}

	int& ret = cache[idx][cur][state];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	if (cur > 0) {
		int nextState = state | (1 << (cur - 1));
		ret = (ret + func(idx + 1, cur - 1, nextState)) % mod;
	}
	if (cur < 9) {
		int nextState = state | (1 << (cur + 1));
		ret = (ret + func(idx + 1, cur + 1, nextState)) % mod;
	}

	return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d" , &N);
    memset(cache,-1,sizeof(cache));
    ll ans = 0;
    for(int i = 1 ; i <= 9 ; i++){
        ans = (ans + func(0, i, 1<<i))%mod;
        // ans += func(0, i, 1<<i)%mod;
    }
    printf("%lld", ans);

    // int ans = 0;
	// for (int i = 1 ; i < 10 ; ++i) {
	// 	ans = (ans + func(0, i, 1 << i)) % MOD;
	// }

	// cout << ans << endl;
}