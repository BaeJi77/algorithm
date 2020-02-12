#include <cstdio>
#include <cstring>
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
=======
#define MAXX 1000000
#include <iostream>
#include <cstdlib>
// #include <string>

>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
#include <iostream>
>>>>>>> 1ff6c3c... 18.05.08

using namespace std;

int t;
string str;
string input;
<<<<<<< HEAD
<<<<<<< HEAD
string result;

=======
int strlength;
string result;


>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
string result;

>>>>>>> 1ff6c3c... 18.05.08
int main(){
	freopen("input.txt", "r", stdin);

	cin>>t;
	cin>>str;
	result = str;
	t--;
	while(t--){
		cin>>input;
		for(int i = 0 ; i < input.size() ; i++){
			bool check = false;
			if(result[i] != input[i]){
				result[i] = '?';		
			}
		}
	}
	cout<<result;
	
}