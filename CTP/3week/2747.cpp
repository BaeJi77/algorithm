#include <cstdio>
#include <cstring>

// #include <vector>

using namespace std;

long long int n;
long long int dp[50];

long long int fib(long long int k){
	if(k == 0 ){
		return 0;
	}else if(k == 1 ){
		return 1;
	}
	long long int &ret = dp[k];
	if(ret != -1) return ret;

	ret = fib(k-1) + fib(k-2);
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);

	memset(dp, -1 , sizeof(dp));


	scanf("%lld" , &n);
	printf("%lld" , fib(n));

}