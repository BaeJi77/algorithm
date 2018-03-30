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
	cin.ignore();
	for(int i = 0 ; i < n ; i++){
		getline(cin , str);
		str[0] = toupper(str[0]);
		cout<<str<<endl;
	}
}