#include <iostream>
#include <string>
// #include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;


int m;
int result;
int n;
int output;


// bool f[1000004];



/**
* 수 이어쓰기
* 에러 : 
100 000 000
*/


int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d" , &n);
	cout<<n;
	// cin>>n;
	// end = n;
	for(int i=0;i<n;i++){
		m++;
		if(m<10){
			cout<<"10이하"<<endl;
			result++;
		}else if(m>=10&&m<100){
			result += 2;
		}else if(m>=100&&m<1000){
			result += 3;
		}else if(m>=1000&&m<10000){
			result += 4;
		}else if(m>=10000&&m<100000){
			result += 5;
		}else if(m>=100000&&m<10000000){
			result += 6;
		}else if(m>=10000000&&m<100000000){
			result += 7;
		}else{
			result += 8;
		}
	}
	printf("%d" , result);
}