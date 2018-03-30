#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
string str;



int main(){
	freopen("input.txt", "r", stdin);

	while(cin>>n){
		if(n==0) break;
		int temp = 0;
		int check = 0;
		int Maxx = -1;
		int sum=0;
		getchar();
		for(int i = 0 ; i < n ; i++){
			getline(cin , str);
			for(int j = check ; j < str.size() ; j++){
				if(str[j]==' '){
					temp = j;
					check = j;
					break;
				}
				temp++;
				check++;
			}
			if(Maxx < temp){
				Maxx = temp;
			}
		}
			cout<<Maxx+1<<endl;
	}
}