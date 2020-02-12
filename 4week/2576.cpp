#include <iostream>
#include <string>
#include <vector>

using namespace std;

int input;
int Min;
int sum;

int main(){
	freopen("input.txt", "r", stdin);

	vector<int> number;

	for(int i=0;i<7;i++){
		cin>>input;
		if(input%2==1){
			number.push_back(input);
		}
	}
	if(number.empty()){
		cout<<"-1";
		return 0;
	}

	for(int i=0;i<number.size();i++){
		sum+=number[i];
	}
	Min = number[0];
	for(int i=1;i<number.size();i++){
		if(Min>number[i])
			Min = number[i];
	}

	cout<<sum<<endl;
	cout<<Min<<endl;
}	
