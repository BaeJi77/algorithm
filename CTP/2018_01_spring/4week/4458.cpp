#include <iostream>
#include <string>
// #include <vector>

using namespace std;

int n;
string str;



int main(){
	freopen("input.txt", "r", stdin);
	
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,str);
		str[0]=toupper((char)str[0]);
		cout<<str<<endl;
	}
	
}