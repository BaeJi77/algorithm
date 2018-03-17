#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	int a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin.ignore();
		cin>>b;
		cout<<a+b<<endl;
	}
}