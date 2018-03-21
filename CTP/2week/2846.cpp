#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;
int Max;
int result;
int dif;
int difsum;


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
			difsum += result;
			if(Max<result)
				Max = difsum;
		}else{
			difsum=0;
		}
		if(arr[i]==arr[i+1])
			dif++;
	}
	if(dif==n){
		cout<<0;
	}else{
		cout<<Max;
	}
}