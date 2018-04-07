#include <cstdio>

using namespace std;

int n;
int sum;

int main(){
	freopen("input.txt", "r", stdin);
	
	for(int i = 0 ; i < 5 ; i ++){
		scanf("%d" , &n);
		sum += n*n;
	}

	printf("%d" , sum%10);
}