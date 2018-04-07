#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string str;
int sum1,sum2;



int main(){
	freopen("input.txt", "r", stdin);

	cin>>str;
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i] == 'I'){
			if(str[i+1] == 'O'){
				if(str[i+2] == 'I'){
					i++;
					sum2++;
				}
			}
		}else if(str[i] == 'J'){
			if(str[i+1] == 'O'){
				if(str[i+2] == 'I'){
					i++;
					sum1++;
				}
			}
		}
	}
	cout<<sum1<<endl;
	cout<<sum2<<endl;
}