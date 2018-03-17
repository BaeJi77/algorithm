#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int input,output;
	int sum=0;
	int max=0;
	for(int i=0;i<4;i++){
		cin>>output>>input;
		sum+=input-output;
		if(max<sum){
			max=sum;
		}
	}
	cout<<max;
	
}