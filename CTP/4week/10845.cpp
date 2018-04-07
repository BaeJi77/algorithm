#include <cstdio>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int t;
string str;
int input;

queue <int> qu;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	while(t--){
		cin>>str;
		if(str == "push"){
			scanf("%d" , &input);
			qu.push(input);
		}else if (str == "front"){
			if(qu.empty()){
				printf("-1\n");
			}else{
				printf("%d\n" , qu.front());
			}
		}else if(str == "back"){
			if(qu.empty()){
				printf("-1\n");
			}else{
				printf("%d\n" , qu.back());
			}
		}else if(str == "size"){
			int quSize = qu.size();
			printf("%d\n" , quSize);
		}else if(str == "empty"){
			printf("%d\n" , qu.empty());
		}else if(str == "pop"){
			if(qu.empty()){
				printf("-1\n");
			}else{
				printf("%d\n" , qu.front());
				qu.pop();
			}
		}
	}
	
}