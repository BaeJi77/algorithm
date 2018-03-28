#include <cstdio>
#include <cstring>
#define MAXX 1000000
// #include <vector>

using namespace std;

int n;
int input;
int sum;
bool arr[MAXX+10];



int main(){
	freopen("input.txt", "r", stdin);

	arr[1]=true;
	arr[2]=true;
	for(int i = 2 ; i < MAXX+10 ; i++){
		if(arr[i] == false){
			for(int j = i*2 ; j < MAXX+10 ; j = j + i){
				arr[j] = true;
			}
		}
	}


	scanf("%d" , &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , &input);
		if(arr[input] == false){
			sum++;
		}
	}

	printf("%d" , sum);
}