#include <cstdio>
#include <string>
#include <iostream>
#include <stack>


using namespace std;

string str;
int t;
char input;
char inputNum;

stack <char> st1;
stack <char> st2;

int main(){
	freopen("input.txt", "r", stdin);
	
	cin>>str;
	for(int i = 0 ; i < str.size() ; i++){
		st1.push(str[i]);
	}

	scanf("%d" , &t);
	while(t--){
		cin>>input;
		if(input == 'P'){
			cin>>inputNum;
			st1.push(inputNum);
		}else if(input == 'L'){
			if(st1.empty()){
				continue;
			} else {
				st2.push(st1.top());
				st1.pop();
			}
		}else if(input == 'D'){
			if(st2.empty()){
				continue;
			} else {
				st1.push(st2.top());
				st2.pop();
			}
		}else if(input == 'B'){
			if(st1.empty()){
				continue;
			}else{
				st1.pop();
			}
			
		}
	}

	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
	while(!st2.empty()){
		printf("%c" , st2.top());
		st2.pop();
	}

}