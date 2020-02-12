#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string str;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>n;
	if(n<=100&&n>=90){
		cout<<"A";
	}else if(n<90&&n>=80){
		cout<<"B";
	}else if(n<80&&n>=70){
		cout<<"C";
	}else if(n<70&&n>=60){
		cout<<"D";
	}else{
		cout<<"F";
	}
}