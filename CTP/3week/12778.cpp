#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>

using namespace std;

int t;
int n;
char check;
string str;



int main(){
	freopen("input.txt", "r", stdin);

	cin>>t;
	while(t--){
		cin>>n;
		cin>>check;
		char arrChar[1000];
		int arrInt[1000];
		if(check == 'C'){
			for(int i = 0 ; i < n ; i ++){
				char input;
				cin>>input;
				// cout<<input;
				arrInt[i] = input-64;
				cout<<arrInt[i]<<" ";
			}
			cout<<endl;
		}else if(check == 'N'){
			for(int i = 0 ; i < n ; i++){
				int input;
				cin>>input;
				// cout<<input+64;
				cout<<(char)(input+64)<<" ";
			}
			cout<<endl;
		}

	}
}