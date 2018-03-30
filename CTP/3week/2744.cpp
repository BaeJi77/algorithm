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

	cin>>str;
	for(int i = 0 ; i < str.length() ; i++){
		if(str[i] >= 65 && str[i] <=90){
			cout<<(char)tolower(str[i]);
		}else{
			cout<<(char)toupper(str[i]);
		}
	}
}