#include <cstdio>
#include <string>
#include <iostream>
#include <map>


using namespace std;

int t,n;
string fir,sec,temp;
int sum;
map <string , int> mp;
map <string , int>::iterator it;



int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d" , &t , &n);
	int temp = t+n;
	for(int i = 0 ; i < temp ; i++){
		cin>>fir;
		mp[fir]++;
	}

	for(it = mp.begin() ; it != mp.end() ; it++){
		if(it->second == 2){
			sum++;
		}
	}
	printf("%d\n", sum);
	for(it = mp.begin() ; it != mp.end() ; it++){
		if(it->second == 2){
			cout<<it->first<<endl;
		}
	}
}