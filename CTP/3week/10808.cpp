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
	for(int i = 0 ; i < 26 ; i++){
		int sum=0;
		for(int j = 0 ; j < str.length() ; j++){
			
			if((int)str[j] == (97+i)){
				sum++;
			}
		}
		cout<<sum<<" ";
		sum=0;
	}
}