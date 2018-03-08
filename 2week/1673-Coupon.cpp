#include <iostream>

using namespace std;

int main(){
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 98bf5d4... Coupon
	// freopen("input.txt", "r", stdin);
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
<<<<<<< HEAD
		}
		cout<<Total<<endl;
	}
=======
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
=======
>>>>>>> 98bf5d4... Coupon
		}
		cout<<Total<<endl;
	}
<<<<<<< HEAD
	cout<<Total;
>>>>>>> d105057... Coupon and ASCII Code
=======
>>>>>>> 98bf5d4... Coupon
}