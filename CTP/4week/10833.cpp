#include <cstdio>

using namespace std;

int t;
int n,m;
int sum;

int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	for(int i = 0 ; i < t ; i++){
		scanf("%d %d" , &n , &m);
		sum += m%n;
	}

	printf("%d" , sum);
}