#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int n, input;
int r, e, c;
string str;
int result;

/**
* 광고
* 
*/


int main(){
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	while(n--){
		cin>>r>>e>>c;
		result =(e-c);
		if(result>r){
			cout<<"advertise"<<endl;
		}else if(result==r){
			cout<<"does not matter"<<endl;
		}else if(result<r){
			cout<<"do not advertise"<<endl;
		}
	}
}