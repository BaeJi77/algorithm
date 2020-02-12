#include <iostream>
#include <string>
// #include <vector>

using namespace std;

int n;
string str;
int upper;
int lower;
int number;
int eymty;
string eymtyStr =" ";




int main(){
	freopen("input.txt", "r", stdin);
	
	while(getline(cin, str)){
		for(int i=0;i<str.length();i++){

			if(str[i] == ' ')
				eymty++;
			if(str[i]>='A'&&str[i]<='Z')
				upper++;
			if(str[i]>='a'&&str[i]<='z')
				lower++;
			if(str[i]>='0'&&str[i]<='9')
				number++;
		}
		cout<<lower<<" "<<upper<<" "<<number<<" "<<eymty<<endl;
		lower=0;
		upper=0;
		number=0;
		eymty=0;

	}
}