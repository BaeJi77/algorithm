#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	int cute;
	cin>>n;
	int a=0,b=0;
	while(n--){
		cin>>cute;
		if(cute==0){
			a++;
		}else{
			b++;
		}
	}
	if(a>b){
		cout<<"Junhee is not cute!";
	}else{
		cout<<"Junhee is cute!";
	}
}