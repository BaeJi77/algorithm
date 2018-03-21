#include <iostream>
#include <string>
// #include <vector>

using namespace std;

 
int n;
string str;
int fallBall=0;

int main(){
	freopen("input.txt", "r", stdin);
	cin>>n;
	while(n--){
		cin.ignore();
		while(getline(cin,str)){
			fallBall = str.find(' ',fallBall);
			cout<<fallBall<<endl;;
		}
		cout<<fallBall+1<<endl;
		fallBall=1;
	}
}