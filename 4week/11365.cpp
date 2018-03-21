#include <iostream>
#include <string>
// #include <vector>

using namespace std;

string str;
int number;


int main(){
	freopen("input.txt", "r", stdin);
	// cin>>str;
	// number = (char)str[0]+3;
	// cout<<(char)number;


	while(getline(cin,str)){
		if(str=="ESC")
			// cout<<"ESC가 나왔다."<<endl;
			break;
		for(int i=0;i<str.length();i++){
			number=(char)str[i]+3;
			cout<<(char)number;
		}
		cout<<"\n";
	}

}