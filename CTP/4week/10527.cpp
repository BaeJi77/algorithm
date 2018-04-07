#include <cstdio>
#include <string>
#include <iostream>
#include <map>


using namespace std;

int t;
int result;
int sum;
string str;
map <string , int> mp1;
map <string , int> mp2;
map <string , int>::iterator it1;
map <string , int>::iterator it2;



int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	for(int i = 0 ; i < t ; i++){
		cin>>str;
		mp1[str]++;
	}

	for(int i = 0 ; i < t ; i++){
		cin>>str;
		mp2[str]++;
	}

	for(it1 = mp1.begin() ; it1 != mp1.end() ; it1++){
		int temp = mp2.find(it1->first)->second;

		if(it1->second < temp) sum+= it1->second;
		if(it1->second >= temp) sum+= temp;

		
	}
	printf("%d\n", sum);
}