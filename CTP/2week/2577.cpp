#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int n;
int result;
int a,b,c;
int num[10];
int arr[1100];
int sum;
string str;


/**
* 대웅 리스펙  
* 아스키 코드 값에 '0'을 빼주면 숫자들이 나온다
*/

int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &a, &b, &c);
	result = a*b*c;

	str = to_string(result);
	// cout<<str;

	for(int i=0; i<str.length();i++){
		num[str[i] - '0']++;
	}

	for(int i=0; i<10 ; i++){
		printf("%d\n",num[i]);
	}
}