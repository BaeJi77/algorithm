#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>

using namespace std;

int n;
string str;
string newStr;

int main(){
	freopen("input.txt", "r", stdin);

	while(1){

		getline(cin , str);
		if(str == "END") break;
		n = str.length();
		for(int i = 0 ; i < n ; i++){
			cout<<str[n-1-i];
		}
		cout<<endl;
	}
}