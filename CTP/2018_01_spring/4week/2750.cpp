#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;
int one;

int main(){
	freopen("input.txt", "r", stdin);

	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>input;
		arr[i] = input;
	}

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(arr[i]>arr[j]){
				one=arr[j];
				arr[j]=arr[i];
				arr[i]=one;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\n";
	}

}