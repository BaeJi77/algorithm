#include <iostream>
#include <string>


using namespace std;


int main(){
	freopen("input.txt", "r", stdin);
	long long int n;
	long long int x=1;
	long long int sum=0;
	cin>>n;
	while(1){
		sum+=x;
		if(sum>n){
			break;
		}
		x++;
	}
	cout<<--x;
}