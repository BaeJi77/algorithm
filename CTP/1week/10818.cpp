#include <iostream>
#include <string>


using namespace std;

int main(){
	int n;
	int Max=-1000000,Min=1000000;
	int Num=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Num;
		if(Max<Num)
			Max=Num;

		if(Min>Num)
			Min=Num;
	}
	cout<<Min<<" "<<Max;
}