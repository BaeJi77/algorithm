#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int hour,min,addMin;
	cin>>hour>>min>>addMin;
	int addHour = (addMin+min)/60;
	min = (min+addMin)%60;
	hour = (hour+addHour)%24;
	cout<<hour<<" "<<min;
}