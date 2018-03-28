#include <cstdio>
#include <cstring>

// #include <vector>

using namespace std;

int n;
int sum;
int dp[15];


int fac(int k){
	if(k == 0){
		return 1;
	}else if ( k== 1){
		return 1;
	}
	int &ret = dp[k];
	if(ret != -1)  return ret;

	ret = k*fac(k-1);
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);

	memset(dp,-1,sizeof(dp));

	scanf("%d" , &n);
	// sum = n/5+n/25+n/125;
	printf("%d" , fac(n));


}