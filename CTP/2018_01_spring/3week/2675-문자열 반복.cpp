#include <iostream>
#include <string>


using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int n=0;
	string s="";
	int T;
	cin>>T;

	while(T--)
	{
		cin>>n>>s;
		
		int StrSize = s.length();

		for(int i=0;i<StrSize;i++){
			for(int j=0;j<n;j++){
				cout<<s[i];
			}

		}
		cout<<endl;
	}
}