#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int a,b;
	int Chi=0,n=0;
	int Coupon=0;
	int addChi=0;
	while(cin>>Chi>>n){
		Coupon = Chi;
		while(1){
			addChi=Coupon/n;
			Chi=Chi+addChi;
			Coupon=Coupon%n;
			Coupon=addChi+Coupon;
			if(Coupon<n)
				break;
		}
		cout<<Chi<<endl;
	}
}