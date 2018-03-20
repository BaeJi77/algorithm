#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;
int result;
int sum;
int Max;



int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	cin>>result;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>input;
		arr[i]=input;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				sum=arr[i]+arr[j]+arr[k];
				if(sum <=result)
					Max = max(Max,sum);
			}

		}
	}
	cout<<Max<<endl;
}
