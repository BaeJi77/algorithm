#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--)
	{
		int a =0; 
		int b =0;

		cin>>a;
		cin.ignore(1,'n');
		cin>>b;
		cout<<a+b<<"\n";
	}
	return 0;
}