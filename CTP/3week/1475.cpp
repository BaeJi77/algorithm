#include <cstdio>
#include <cstring>
#define MAXX 1000000
#include <iostream>
#include <cstdlib>
// #include <string>


using namespace std;

string n;
int Maxx;
//arr[9] = [c0,c1,c2,c3,c4,c5,c69,c7,c8]
//			0 , 1, 2, 3, 4, 5, 6, 7, 8
int arr[9];

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
		/*
		switch(atol(n[i])){
			case 0:
			arr[0]+=2;
			break;
			case 1:
			arr[1]+=2;
			break;
			case 2:
			arr[2]+=2;
			break;
			case 3:
			arr[3]+=2;
			break;
			case 4:
			arr[4]+=2;
			break;
			case 5:
			arr[5]+=2;
			break;
			case 6:
			arr[6]++;
			break;
			case 9:
			arr[6]++;
			cout<<"arr[6]++"<<endl;
			break;
			case 7:
			arr[7]+=2;
			break;
			case 8:
			arr[8]+=2;
			break;
		}
		*/
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