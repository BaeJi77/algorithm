#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

long long int n;
long long int result;
int input;
long long int sum;




/**
* longlong의 필요성  
* int는 21억까지 
*/

int main(){
	freopen("input.txt", "r", stdin);

	scanf("%lld" , &n);
	while(1){
		sum++;
		result+=sum;
		if(n<result)
			break;

	}
	printf("%lld" , --sum);
}