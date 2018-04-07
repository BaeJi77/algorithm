#include <cstdio>
#include <string>
#include <iostream>
#include <queue>


using namespace std;

queue <int> qu;
int n,m;



int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; i++) qu.push(i);

	
	printf("<");
	while(!qu.empty()){
		for(int i = 0 ; i < m-1 ; i++){
			int temp = qu.front();
			qu.pop();
			qu.push(temp);
		}
		printf("%d" , qu.front());
		qu.pop();
		if(!qu.empty()) printf(", ");
	}

	printf(">");
	
	
}