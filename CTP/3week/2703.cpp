#include <iostream>
#include <string>

using namespace std;

int t;
string str;
string option;

int main() {
	freopen("input.txt", "r", stdin);
	cin>>t;
	cout<<t;
	getchar();

	while(t--){
		getline(cin , str);
		// cout<<str;
		getline(cin , option);
		for(int i = 0 ; i < str.size() ; i++){
			if(str[i] == ' ') cout<<' ';
			if(str[i] == 'A') cout<<option[0];
			if(str[i] == 'B') cout<<option[1];
			if(str[i] == 'C') cout<<option[2];
			if(str[i] == 'D') cout<<option[3];
			if(str[i] == 'E') cout<<option[4];
			if(str[i] == 'F') cout<<option[5];
			if(str[i] == 'G') cout<<option[6];
			if(str[i] == 'H') cout<<option[7];
			if(str[i] == 'I') cout<<option[8];
			if(str[i] == 'J') cout<<option[9];
			if(str[i] == 'K') cout<<option[10];
			if(str[i] == 'L') cout<<option[11];
			if(str[i] == 'M') cout<<option[12];
			if(str[i] == 'N') cout<<option[13];
			if(str[i] == 'O') cout<<option[14];
			if(str[i] == 'P') cout<<option[15];
			if(str[i] == 'Q') cout<<option[16];
			if(str[i] == 'R') cout<<option[17];
			if(str[i] == 'S') cout<<option[18];
			if(str[i] == 'T') cout<<option[19];
			if(str[i] == 'U') cout<<option[20];
			if(str[i] == 'V') cout<<option[21];
			if(str[i] == 'W') cout<<option[22];
			if(str[i] == 'X') cout<<option[23];
			if(str[i] == 'Y') cout<<option[24];
			if(str[i] == 'Z') cout<<option[25];
		}
		cout<<endl;
	}
}