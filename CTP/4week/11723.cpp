#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int t;
int input;
<<<<<<< HEAD
<<<<<<< HEAD
char str[10];
=======
string str;
>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
char str[10];
>>>>>>> 1ff6c3c... 18.05.08
set <int> se; 
// set <int>::iterator it;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	for(int i = 0 ; i < t ; i ++){
<<<<<<< HEAD
<<<<<<< HEAD
		scanf("%s" , str);
		if(str[0] == 'a' && str[1] == 'd'){
=======
		cin>>str;
		if(str == "add"){
>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
		scanf("%s" , str);
		if(str[0] == 'a' && str[1] == 'd'){
>>>>>>> 1ff6c3c... 18.05.08
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
<<<<<<< HEAD
<<<<<<< HEAD
		}else if(str[0] == 'a'){
=======
		}else if(str == "all"){
>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
		}else if(str[0] == 'a'){
>>>>>>> 1ff6c3c... 18.05.08
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