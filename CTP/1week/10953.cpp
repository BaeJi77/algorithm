#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	int a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		cout<<"Case #"<<i+1<<": "<<a+b<<"\n";
	}
}