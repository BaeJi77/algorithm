#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int n;
int result;
int input;
int sum;




/**
* 보물
* 아스키 코드 값에 '0'을 빼주면 숫자들이 나온다
*/

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int arr1[n];
	int arr2[n];

	for(int i=0; i < n ; i++){
		scanf("%d" , &arr1[i]);
	}
	for(int i=0; i < n ; i++){
		scanf("%d" , &arr2[i]);
	}
	sort(arr1,arr1+n);
	sort(arr2,arr2+n);

	for(int i=0; i < n ; i++){
		sum+= arr1[i]*arr2[n-1-i];
	}
	cout<<sum;
}