#include <iostream>
#include <string>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> 46dfa63... 18.03.23
=======
>>>>>>> 1ff6c3c... 18.05.08
#include <cstdio>
#include <algorithm>


using namespace std;

int n, input;
int arr[9];
int sum, twosum, no1,no2;
/**
* 정렬
* STL algorithm
*/


int main(){
	freopen("input.txt", "r", stdin);

	for(int i=0;i<9;i++){
		scanf("%d", arr + i);
		sum += arr[i];
	}

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(i==j) continue;
			twosum = arr[i]+arr[j];
			if((sum - twosum) == 100){
				no1 = arr[i];
				no2 = arr[j];
			}
		}
	}

	sort(arr,arr+9);
	for(int i=0;i<9;i++){
		if(arr[i]==no1||arr[i]==no2)
			continue;
		printf("%d\n", arr[i]);
	}
}