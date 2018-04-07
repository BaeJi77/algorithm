#include <cstdio>
#include <string>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

int t;
string str;
int input;
string result;
bool check;

stack <int> st;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	while(t--){
		cin>>str;
		for(int i = 0 ; i < str.size() ; i++){
			if(str[i] == '('){
				st.push(1);
			} else if(str[i] == ')'){
				if(st.empty()){
					check = false;
					break;
				} else {
					st.pop();
					check = true;
				}
			}
		}
		if(st.empty() == false){
			check = false;
		}
		
		if(check == false){
			printf("NO\n");
		}else {
			printf("YES\n");
		}
		check = false;
		while(!st.empty()){
			st.pop();
		}
	}

	
}