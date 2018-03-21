#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int re;
int temp;
int result;



int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	re = n/5+1;
	while(re--){
		if(n%5==0){
			result = n/5;
			break;
		}
		// cout<<"re : "<<re<<endl;
		temp = n-re*5;
		if(temp%3==0){
			result = re+temp/3;
			break;
		}
		if(n%5!=0&&n%3!=0){
		result = -1;
	}
	}
	
	cout<<result;
}