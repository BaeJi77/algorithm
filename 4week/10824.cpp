#include <iostream>
#include <string>
// #include <vector>

using namespace std;

string a,b,c,d;


int main(){
	freopen("input.txt", "r", stdin);
	
	cin>>a>>b>>c>>d;

	string ab=a+b;
	string cd=c+d;
	cout<<stol(ab)+stol(cd);
}