#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>

using namespace std;

int n;
int input;
string str;
int a,b,c,d;


int main(){
	freopen("input.txt", "r", stdin);

	while(getline(cin , str)){
		for(int i = 0 ; i < str.length() ; i++){
			if(str[i] >= 'a' && str[i] <= 'z'){
				a++;
			}else if(str[i] >= 'A' && str[i] <='Z'){
				b++;
			}else if(str[i] == ' '){
				c++;
			}else{
				d++;
			}
		}
		cout<<a<<" "<<b<<" "<<d<<" "<<c<<endl;
		a=0;
		b=0;
		c=0;
		d=0;
	}
}