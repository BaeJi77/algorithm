#include <iostream>
#include <string>
#include <vector>

using namespace std;

//2중 배열 사용해서
//색칠 되는 부분을 1로 바꾸어서
//나중에 1인 친구들을 다 더함

int n;
int x,y;
int arr[100][100];
int sum;


int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			arr[i][j]=0;
		}
	}

	while(n--){
		cin>>x>>y;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				arr[x+i][y+j]=1;
			}
		}
	}

	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(arr[i][j]==1){
				sum++;
			}
		}
	}
	cout<<sum;
}
