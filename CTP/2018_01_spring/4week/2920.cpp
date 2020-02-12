#include <iostream>
#include <string>
// #include <vector>



using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	
	int asc[8]={1,2,3,4,5,6,7,8};
	int des[8]={8,7,6,5,4,3,2,1};

	int num[8];
	int input;
	int rightAsc=0;
	int rightDes=0;
	for(int i=0;i<8;i++){
		cin>>input;
		num[i]=input;
	}
	for(int i=0;i<8;i++){
		if(asc[i]==num[i]){
			rightAsc++;
		}else if(des[i]==num[i]){
			rightDes++;
		}else{
			break;
		}
	}
	if(rightAsc==8){
		cout<<"ascending";
	}else if(rightDes==8){
		cout<<"descending";
	}else{
		cout<<"mixed";
	}

}