#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>

using namespace std;

int n;
int input;
string str;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>n;
	while(n--){
		cin>>input;
		cin>>str;
		for(int i = 0 ; i < str.length() ; i++){
			for(int j = 0 ; j < input ; j++){
				cout<<str[i];
			}
		}
		cout<<endl;
	}
}