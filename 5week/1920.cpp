#include <cstdio>
#include <algorithm>


using namespace std;


int n,m,temp;
int arr[100010];

int goodSort(int n , int key){
	int start = 0;
	int end = n-1; // 길이
	int mid;

	while(end - start >= 0){
		mid = (start + end)/2;

		if(arr[mid] == key){
			printf("1\n");
			return 0;
		}else if(arr[mid] > key){
			end = mid - 1;
		}else if(arr[mid] < key){
			start = mid + 1;
		}
	}

	printf("0\n");
	return 0;


}

int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d", &n );
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , &arr[i]);
	}

	sort(arr,arr+n);

	scanf("%d" , &m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d" , &temp);
		goodSort(n , temp);
	}


}


