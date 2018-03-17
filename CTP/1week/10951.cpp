#include <iostream>
#include <string>


using namespace std;

int main(){
	// freopen("input.txt", "r", stdin);
	// int n;
	int a,b;
	while(cin>>a>>b){
		if(a==0 && b==0)
			break;
		cout<<a+b<<endl;
	}
}