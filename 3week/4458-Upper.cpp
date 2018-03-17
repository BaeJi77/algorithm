#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n=0;

	cin>>n;
	cin.ignore();
	string Upper="";
	
	// while(getline(cin,Upper)){
	// 	Upper[0] = toupper(Upper[0]);
	// 	cout<<Upper<<endl;
	// 	Upper="";
	// }
	for(int i=0;i<n;i++){

		getline(cin,Upper);
		Upper[0] = toupper(Upper[0]);
		cout<<Upper<<endl;
	}
}