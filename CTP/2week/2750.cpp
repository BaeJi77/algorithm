#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int n;
int input;
int arr[1100];
/**
* 정렬
* STL algorithm
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