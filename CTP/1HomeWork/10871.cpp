#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int x;
	int n;
	cin>>n>>x;
	int Number[n];
	for(int i=0;i<n;i++){
		cin>>Number[i];
	}

	for(int i=0;i<n;i++){
		if(x>Number[i])
			cout<<Number[i]<<" ";
	}


}