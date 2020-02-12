#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int a,b,c,d;
	int sum=0;
	int max=0;
	for(int i=0;i<2;i++){
		cin>>a>>b>>c>>d;
		sum=a+b+c+d;
		if(max<sum)
			max=sum;
	}
	cout<<max;
}