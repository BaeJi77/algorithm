#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;
int Max;
int result;
int dif;
<<<<<<< HEAD
<<<<<<< HEAD
int difsum;
=======
>>>>>>> ecb026a... 18.03.20
=======
int difsum;
>>>>>>> 35249aa... 18.03.21


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
<<<<<<< HEAD
<<<<<<< HEAD
			difsum += result;
			if(Max<difsum)
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
=======
=======
			difsum += result;
<<<<<<< HEAD
>>>>>>> 35249aa... 18.03.21
			if(Max<result)
=======
			if(Max<difsum)
>>>>>>> 46dfa63... 18.03.23
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
<<<<<<< HEAD
	cout<<Max;
>>>>>>> ecb026a... 18.03.20
=======
>>>>>>> 35249aa... 18.03.21
}