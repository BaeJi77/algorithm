#include <iostream>
#include <string>
// #include <vector>

using namespace std;

int n;
int input;
string str;
int temp;
int sum;


int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	int good=n;
	while(n--){
		cin>>str;
		for(int i=0;i<str.length();i++){
			if(str[i]=='O'){
				temp++;
				sum+=temp;
			}else{
				temp=0;
			}
		}
		cout<<sum<<endl;
		sum=0;
		temp=0;
	}

}