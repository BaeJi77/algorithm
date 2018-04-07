#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#define MAXX 1000000

using namespace std;

int t;
int n,m;
int temp;
int sum2;
int sum5;


int search2(int num){
	int sum=0;
	long long now = 2;
	while(now <= num){
		sum += num/now;
		now *= 2;
	}
	return sum;
}

int search5(int num){
	int sum=0;
	long long now = 5;
	while(now <= num){
		sum += num/now;
		now *= 5;
	}
	return sum;
}



int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d" , &n , &m);
	sum2= search2(n) - search2(m) - search2(n-m);
	sum5= search5(n) - search5(m) - search5(n-m);
	if(sum2>=sum5){
		printf("%d", sum5);
	}else{
		printf("%d", sum2);
	}


}