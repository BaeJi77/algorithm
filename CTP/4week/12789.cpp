#include <cstdio>
#include <string>
#include <queue>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int t;
string str;
int input;
string result;
int check;

stack <int> st;
queue <int> qu;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &input);
		qu.push(input);
	}
	check++;
	while(1){
		if(st.empty() || st.top() != check){
			if(qu.front() == check){
				qu.pop();
				check++;
			}else{
				int temp = qu.front();
				st.push(temp);
				qu.pop();
			}
		}else{
			st.pop();
			check++;
		}
		if(qu.empty() == true){
			if(st.empty()){
				printf("Nice");
				break;
			}else if(st.top() != check){
				printf("Sad");
				break;
			}
		}
	}
	
	
}