#include <iostream>
#include <string>
// #include <vector>

using namespace std;

string n;



int main(){
	freopen("input.txt", "r", stdin);
	
	cin>>n;
	for(int i=0;i<n.length();i++){
		if(n[i]>=65&&n[i]<=90){
			cout<<(char)tolower(n[i]);
		}
		if(n[i]>=97&&n[i]<=122){
			cout<<(char)toupper(n[i]);
		}
	}
}