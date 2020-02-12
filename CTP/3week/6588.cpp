#include <cstdio>
#include <cstring>
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#define MAXX 1000000

using namespace std;

int n=3;
int m;
int result;
int input;
bool arr[MAXX+10];


int main(){
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
=======
#define MAXX 1000000
// #include <vector>
// #include <algorithm>
=======
>>>>>>> 1ff6c3c... 18.05.08
#include <iostream>
#define MAXX 1000000

using namespace std;

int n=3;
int m;
int result;
int input;
bool arr[MAXX+10];


int main(){
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
<<<<<<< HEAD

>>>>>>> 6e56ece... 18.03.27
=======
>>>>>>> 9c051f4... 18.03.30
}