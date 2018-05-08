#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int t;
int input;
int sum1;
int sum2;
int arr1[9];
int arr2[9];
bool check;
vector <int> vt;


int main(){
	freopen("input.txt", "r", stdin);
	for(int i = 0 ; i < 9 ; i++){
		scanf("%d" , &arr1[i]);

	}
	for(int i = 0 ; i < 9 ; i++){
		scanf("%d" , &arr2[i]);
	}


	for(int i = 0 ; i < 9 ; i++){
		vt.push_back(arr1[i]);
		vt.push_back(arr2[i]);
	}

	for(int i = 0 ; i < 18 ; i++){
		if(i == 0 || i % 2 == 0){
			sum1 += vt[i];
		}else if(i % 2 == 1){
			sum2 += vt[i];
		}
		if(sum1 > sum2) {
			check = true;
		}

	}

	if(check == true){
		if(sum1 < sum2){
			printf("Yes");
		}else{
			printf("No");
		}
	}else{
		printf("No");
	}
}