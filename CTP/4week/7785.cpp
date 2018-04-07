#include <cstdio>
#include <string>
#include <iostream>
// #include <set>
#include <map>

using namespace std;

int t;
int input;
string first;
string second;

map <string , string> Map;
map <string , string>::iterator it;
map <string , string>::reverse_iterator rit;

int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	for(int i = 0 ; i < t ; i++){
		cin>>first>>second;
		Map[first] = second;
	}

	for(rit = Map.rbegin() ; rit != Map.rend() ; rit++){
		if(rit->second != "leave"){
			cout<<rit->first<<endl;
		}
	}

}