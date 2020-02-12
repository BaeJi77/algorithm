#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <iostream>



using namespace std;

int t;
string str;
stack <int> st;
int input;


int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d" , &t);
	while(t--){
		cin>>str;
		if(str == "push"){
			scanf("%d", &input);
			st.push(input);
		}else if(str == "top"){
			if(st.empty()){
				printf("-1\n");
			}else{
				printf("%d\n" , st.top());
			}
		}else if(str == "size"){
			if(st.empty()){
				printf("0\n");
			}else{
				int stSize = st.size();
				printf("%d\n" , stSize);
			}
		}else if(str == "empty"){
			printf("%d\n" , st.empty());
		}else if(str == "pop"){
			if(st.empty()){
				printf("-1\n");
			}else{
				printf("%d\n" , st.top());
				st.pop();
			}
		}
	}
}

