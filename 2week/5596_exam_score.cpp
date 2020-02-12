#include <iostream>

using namespace std;


int main(){

	// int a;
	int S,T=0;

	//민국이의 점수
	for(int i=0;i<4;i++){
		int a;
		cin>>a;
		S=S+a;
	}
	//만세의 점수
	for(int i=0;i<4;i++){
		int a;
		cin>>a;
		T=T+a;
	}
	if(S>=T){
		cout<<S;
	}if else(S<T){
		cout<<T;
	}

	return 0;
}