#include <cstdio>
#include <cstring>
#define MAXX 1000000
// #include <vector>
// #include <algorithm>
#include <iostream>

using namespace std;

int n=3;
int m;
int result;
int input;
// int Min;
// int Max;
// int input;
// int sum;
bool arr[MAXX+10];
// vector <int> vt;



int main(){
	freopen("input.txt", "r", stdin);


	arr[0]=true;
	arr[1]=true;
	for(int i = 2 ; i*i < MAXX+10 ; i++){
		if(arr[i]==false){
			for(int j = 2*i ; j< MAXX+10 ; j = j + i){
				if(arr[j]==true)  continue;
				arr[j] = true;
			}
		}
	}

	int i, j;
	while(scanf("%d", &n) && n){
		for(i=1, j=n-1; i<= n/2; i+=2, j-=2){
			if(arr[i] || arr[j]) continue;
			if(i+j == n){
				printf("%d = %d + %d\n" , n , i , j);
				break;
			}
		}
	}
}