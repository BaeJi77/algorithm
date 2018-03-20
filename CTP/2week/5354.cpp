#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int input;


int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	int good=n;
	while(n--){
		cin>>input;
		for(int i=0;i<input;i++){
			if(i==0||i==(input-1)){
				for(int j=0;j<input;j++){
					cout<<"#";
				}
				cout<<"\n";
			}else{
				for(int j=0;j<input;j++){
					if(j==0||j==(input-1)){
						cout<<"#";
					}else{
						cout<<"J";
					}
				}
				cout<<"\n";
			}
		}
		cout<<"\n";
	}
}