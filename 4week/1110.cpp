#include <iostream>
#include <string>
// #include <vector>

using namespace std;

int n;
int cycleNum = 0;
int second;
int first;
int sum;

int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	int cycle = n;
	
	do{
		second = n/10;
		first = n%10;
		sum = second+first;
		sum = sum%10;
		n = first*10+sum;
		cycleNum++;
	}while(cycle!=n);
	
	cout<<cycleNum;

}