#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int n,m;
char input[30];
map <string , int> mp;
string arr[100010];



int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d" , &n ,&m);
	for(int i = 1 ; i <= n ; i++){
		scanf("%s" , input);
		mp[input] = i;
		arr[i] = input;
	}

	for(int i = 0 ; i < m ; i++){
		scanf("%s" , input);
		int check = input[0] - '0';
		if(check >= 0 && check <= 9){
			int toInt = stoi(input);
			cout<<arr[stoi(input)]<<"\n";
		}else {
			printf("%d\n" , mp[input]);
		}
		
	}
}