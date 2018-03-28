#include <cstdio>

using namespace std;

int n;
int result;


int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d" , &n);

	result = n*(n-1)*(n-2)*(n-3)/(2*3*4);

	printf("%d" , result);

}