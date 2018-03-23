#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int a,b,v;
int sum;
int day;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>a>>b>>v;
	while(1){
		day++;
		sum+=a;
		if(sum==v){
			cout<<day;
			break;
		}
		sum=sum-b;
	}
}