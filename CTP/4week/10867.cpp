#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int t;
int input;
string str;
set <int> se; 
set <int>::iterator it;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	for(int i = 0 ; i < t ; i ++){
		cin>>str;
		if(str == "add"){
			scanf("%d" , input);
			se.insert(input);
		}else if(str == "remove"){
			scanf("%d" , input)
			if(se.find(input) == se.end()) continue;
			it = se.find(input);
			se.erase(it)
		}else if(str == "check"){

		}else if(str == "toggle"){

		}else if(str == "all"){

		}else{
			//str == empty;


		}
	}

}