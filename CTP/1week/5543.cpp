#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int MinHam=2000;
	int MinDrink=2000;
	int Ham,Drink;
	for(int i=0;i<3;i++){
		cin>>Ham;
		if(Ham<MinHam)
			MinHam=Ham;
	}
	for(int i=0;i<2;i++){
		cin>>Drink;
		if(Drink<MinDrink)
			MinDrink=Drink;
	}
	cout<<MinHam+MinDrink-50;
}