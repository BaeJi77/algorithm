#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s="";
int loopNumber;

int main(){
	freopen("input.txt", "r", stdin);

	cin>>s;
	loopNumber = s.length()/10;

	for(int i=0;i<loopNumber+1;i++){
		cout<<s.substr(0+i*10,10)<<"\n";
	}
}