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
	for(int i = 0 ; i < n ; i++){
		cin>>str;
		cout<<str[0]<<str[str.length()-1]<<endl;
	}
}