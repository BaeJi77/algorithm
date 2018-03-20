#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;
int sum;


int main(){
	freopen("input.txt", "r", stdin);

	int arr[3];
	for(int j=0;j<3;j++){
		for(int i=0;i<4;i++){
			cin>>input;
			if(input==0)
				sum++;
		}
		arr[j]=sum;
		sum=0;
	}

	for(int i=0;i<3;i++){
		if(arr[i]==0)
			cout<<"E"<<endl;
		if(arr[i]==1)
			cout<<"A"<<endl;
		if(arr[i]==2)
			cout<<"B"<<endl;
		if(arr[i]==3)
			cout<<"C"<<endl;
		if(arr[i]==4)
			cout<<"D"<<endl;
	}
}