#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string str;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>str;
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i] >= 'D' && str[i] <= 'Z'){
			int temp = str[i] - 3;
			str[i] = (char)temp;
		}else if(str[i] == 'A'){
			str[i] = 'X';
		}else if(str[i] == 'B'){
			str[i] = 'Y';
		}else if(str[i] == 'C'){
			str[i] = 'Z';
		}
	}

	cout<<str;
}