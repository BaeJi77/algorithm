#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>
#include <cstdlib>
// #include <string>


using namespace std;

string n;
int Maxx;
int arr[9];
//arr[9] = [c0,c1,c2,c3,c4,c5,c69,c7,c8]
//			0 , 1, 2, 3, 4, 5, 6, 7, 8

int main(){
	freopen("input.txt", "r", stdin);

	cin>>n;
	for(int i = 0 ; i < n.length() ; i++){
		int change = n[i] - '0';
		if(change == 6 || change == 9){
			arr[6]++;
		}else {
			arr[change] += 2;
		}

	}
	for(int i = 0 ; i < 9 ; i++){
		if(arr[i] > Maxx)
			Maxx = arr[i];
	}

	if(Maxx%2 == 1){
		cout<<Maxx/2+1<<endl;
	}else if(Maxx%2 ==0){
		cout<<Maxx/2<<endl;
	}
}