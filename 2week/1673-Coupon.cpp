#include <iostream>

using namespace std;

int main(){

	freopen("input.txt", "r", stdin);
	int Total=0,n=0,stemp=0;

	while(cin>>Total>>n){
		stemp = Total;
		int AddChi = 0;
		while(1){
			AddChi=stemp/n;
			Total=Total+AddChi;
			stemp=stemp%n;
			stemp=stemp+AddChi;
			if(stemp<n){
				break;
			}
		}
		cout<<Total<<endl;
	}
}