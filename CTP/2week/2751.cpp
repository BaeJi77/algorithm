#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int n;
int input;
int arr[10000040];
/**
* 정렬
* STL algorithm
* 배열은 전역으로 선언 
*/


int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&input);
		arr[i] = input;
	}

	sort(arr,arr+n);

	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}