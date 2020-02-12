#include <cstdio>
#include <string>
#include <iostream>
#include <stack>


using namespace std;

string str;
int sum;
int temp = 1;
stack <int> st;


int main(){
	freopen("input.txt", "r", stdin);
	
	cin>>str;
	for(int i = 0 ; i < str.size(); i++){
		if(str[i] == '('){
			if(str[i+1] == ']') {
				printf("0\n");
				return 0;
			}
			st.push(2);
			// temp *= 2;
		}else if(str[i] == '['){
			if(str[i+1] == ')'){
				printf("0\n");
				return 0;
			}
			st.push(3);
			// temp *= 3;
		}else if(str[i] == ')'){
			st.pop();
			temp *= 2;
			// temp /= 2;
			sum += temp;

			printf("%d 만큼 더해짐\n", temp);
			temp /= 2;
			
		}else if(str[i] == ']'){
			st.pop();
			temp *= 3;
			// temp /= 3;
			sum += temp;
			printf("%d 만큼 더해짐\n", temp);
			temp /= 3;
		}
	}
	if(st.empty()){
		printf("%d\n", sum);
	}else {
		printf("0\n");
	}
}