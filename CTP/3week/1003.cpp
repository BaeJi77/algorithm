#include <cstdio>
#include <cstring>

// #include <vector>

using namespace std;

int input1, input2;
int sum0,sum1;

int dp0[45];
int dp1[45];


// int 

int fibonacci0(int n) {

	int& ret = dp0[n];
	if(ret != -1)	return ret;


	ret = fibonacci0(n-1) + fibonacci0(n-2);
	return ret;

}

int fibonacci1(int n) {

	int& ret = dp1[n];
	if(ret != -1)	return ret;

	ret = fibonacci1(n-1) + fibonacci1(n-2);
	return ret;
	
}


int main(){
	freopen("input.txt", "r", stdin);

	memset(dp0,-1,sizeof(dp0));
	memset(dp1,-1,sizeof(dp1));

	dp0[0] = 1;
	dp0[1] = 0;
	dp1[0] = 0;
	dp1[1] = 1;

	scanf("%d" , &input1);
	
	for(int i = 0 ; i < input1 ; i ++ ){
		sum0 = 0;
		sum1 = 0;
		scanf("%d" , &input2);
		printf("%d %d\n", fibonacci0(input2) , fibonacci1(input2));
	}

}