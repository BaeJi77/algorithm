#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>

using namespace std;

int n;
int input;
string str;
int cnt = 0;

int main(){
	freopen("input.txt", "r", stdin);

	cin>>n;
	cin.ignore();
	for(int i = 0 ; i < n ; i++){
		getline(cin , str);
		int temp=0;
		int tempLength=0;

		for(int j = 0 ; j < str.length() ; j++){
			if(str[j] == ' '){
				temp = j;
				tempLength = str.length() - j;
				break;
			}


		}
		string output = "god";
		for(int j = temp ; j < str.length() ; j++){
			if(str[j]==' ') continue;
			output += str[j];
		
		}
		cout<<output<<endl;
	}
}