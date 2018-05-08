#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int t;
string str;
string input;
string result;

int main(){
	freopen("input.txt", "r", stdin);

	cin>>t;
	cin>>str;
	result = str;
	t--;
	while(t--){
		cin>>input;
		for(int i = 0 ; i < input.size() ; i++){
			bool check = false;
			if(result[i] != input[i]){
				result[i] = '?';		
			}
		}
	}
	cout<<result;
	
}