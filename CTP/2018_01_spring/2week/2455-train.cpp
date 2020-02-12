#include <iostream>

using namespace std;

int main(){
	
	int Max=0;

	for(int i=0;i<4;i++){
		int On=0;
		int Off=0;
		cin>>Off>>On;
		cout<<"\n";
		int Now=0;
		Now=Max+On-Off;
		if(Now>Max){
			Max=Now;
		}
	}
	cout<<Max;
	
}