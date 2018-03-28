#include <cstdio>
#include <cstring>
#define MAXX 1000000
// #include <vector>

using namespace std;

int n,m;
int check;
int result;
// int input;
// int sum;
bool arr[MAXX+10];



int main(){
	freopen("input.txt", "r", stdin);

	arr[0]=true;
	arr[1]=true;
	scanf("%d %d" , &n , &m);
	for(int i = 2 ; i <= n ; i++){
		if(arr[i] == false){
			check++;
			if(m == check) {
				result = i;
				break;
			}
			for(int j = i+i ; j <= n ; j = j + i){
				if(arr[j])	continue;
				check++;
				if(m == check){
					result = j;
					break;
				}
				arr[j] = true;
			}


		}
	}

	printf("%d" , result);
}