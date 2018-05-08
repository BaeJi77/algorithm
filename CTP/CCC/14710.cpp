#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n,m;

int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d" , &n , &m);
	if(n*12 % 360 == m){
		printf("O\n");
	}else{
		printf("X\n");
	}
}