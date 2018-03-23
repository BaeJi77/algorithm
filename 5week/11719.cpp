#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;


int main(){
	freopen("input.txt", "r", stdin);

	while(getline(cin,str)){
		cout<<str<<endl;
	}
}