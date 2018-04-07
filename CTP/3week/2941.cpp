#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>
#include <cstdlib>
// #include <string>


using namespace std;

int t;
int sum;
string input;



int main(){
	freopen("input.txt", "r", stdin);

	cin>>input;
	for(int i = 0 ; i < input.size() ; i++){
		if(input[i] == 'c'){
			if(input[i+1] == '='){
				i++;
				sum++;
			} else if(input[i+1] == '-'){
				i++;
				sum++;
			} else sum++;
		}else if(input[i] == 'd'){
			if(input[i+1] == 'z'){
				if(input[i+2] == '='){
					i = i+2;
					sum++;
				}
			} else if(input[i+1] == '-'){
				i++;
				sum++;
			} else sum++;
		}else if(input[i] == 'l'){
			if(input[i+1] == 'j'){
				i++;
				sum++;
			}else
			sum++;
		}else if(input[i] == 'n'){
			if(input[i+1] == 'j'){
				i++;
				sum++;
			}else sum++;
			
		}else if(input[i] == 's'){
			if(input[i+1] == '='){
				i++;
				sum++;
			}else sum++;
			
		}else if(input[i] == 'z'){
			if(input[i+1] == '='){
				i++;
				sum++;
			}else sum++;
			
		}else{
			sum++;
		}
	}
	cout<<sum;
	
}