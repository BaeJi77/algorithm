#include <cstdio>
#include <string>
#include <iostream>
#include <stack>


using namespace std;

string str;
int sum;
stack <int> st;


int main(){
	freopen("input.txt", "r", stdin);
	
	cin>>str;
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i] == '('){
			st.push(1);
		}else if(str[i] == ')'){
			st.pop();
			if(str[i-1] == '('){
				sum += st.size();
			}
			if(str[i+1] ==')'){
				sum++;
			}
		}
	}
	if(st.empty()){
		printf("%d\n", sum);
	}
}