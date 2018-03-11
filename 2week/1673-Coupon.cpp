#include <iostream>

using namespace std;

int main(){
	int Total,n;
	cin>>Total>>n;
	n=n+Total;
	while(1){
		int AddChi=n/4;
		Total=Total+AddChi;
		n=n%4;
		n=n+AddChi;
		if(n<4){
			break;
		}
	}
	cout<<Total;
}