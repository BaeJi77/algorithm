#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int t;
int input;
char str[10];
set <int> se; 
// set <int>::iterator it;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	for(int i = 0 ; i < t ; i ++){
		scanf("%s" , str);
		if(str[0] == 'a' && str[1] == 'd'){
			scanf("%d" , &input);
			se.insert(input);
		}else if(str[0] == 'r'){
			scanf("%d" , &input);
			if(!se.count(input)) continue;
			// it = se.find(input);
			se.erase(input);
		}else if(str[0] == 'c'){
			scanf("%d" , &input);
			int count = se.count(input);
			printf("%d\n" , count);
		}else if(str[0] == 't'){
			scanf("%d" , &input);
			if(se.count(input)){
				se.erase(input);
			}else{
				se.insert(input);
			}
		}else if(str[0] == 'a'){
			if(se.size() == 20) continue;
			for(int i = 1 ; i <= 20 ; i ++){
				se.insert(i);
			}
		}else{
			//str == empty;
			se.clear();
		}
	}

}