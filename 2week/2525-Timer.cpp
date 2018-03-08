#include <iostream>

using namespace std;

int main(){
	
	int hour;
	int min;
	int add;
	cin>>hour>>min>>add;

	int Add_Hour = (min+add)/60;
	min = (min+add)%60;
	hour = hour+Add_Hour;
	hour = hour%24;

	cout<<hour<<" "<<min;
}