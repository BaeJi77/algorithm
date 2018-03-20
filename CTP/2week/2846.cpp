#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;
int Max;
int result;
int dif;


int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>input;
		arr[i]=input;
	}
	for(int i=0;i<n-1;i++){
		if(arr[i]<arr[i+1]){
			result = arr[i+1]-arr[i];
			if(Max<result)
				Max = result;
			if(arr[i]==arr[i+1])
				dif++;
		}
	}
	if(dif==n){
		cout<<0;
	}
	cout<<Max;
}