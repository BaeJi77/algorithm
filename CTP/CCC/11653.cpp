#include <cstdio>
#include <string>

using namespace std;

int t;
int input;
int num=2;


int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	if(t == 1){
		return 0;
	}
	while(t != 1){
		if(t%num == 0){
			printf("%d\n", num);
			t /= num;
			num = 2;
		}else{
			num++;
		}
	}	
}