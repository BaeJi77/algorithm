#include <cstdio>
#include <cstring>


using namespace std;
long long n,m,temp;
long long check;

int main(){
	freopen("input.txt", "r", stdin);

	scanf("%lld %lld" , &n , &m);
	if(n>m){
		temp = n;
		n = m;
		m = temp;
	}
	check = n+1;
	long long dif = m-n-1;
	if(m-n==0){
		printf("0\n");
	}else {
		printf("%lld\n", dif);	
	}

	for(long long i = n+1 ; i < m ; i++){
		printf("%lld ", i);
	}
}