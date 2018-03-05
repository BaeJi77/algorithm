#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    //위쪽 별찍기
    for(int i=0;i<n;i++){
    	for(int j=0;j<n-i-1;j++){
    		cout<<" ";
    	}
    	for(int j=0;j<2*i+1;j++){
    		cout<<"*";
    	}
    	cout<<endl;
    }
    //아래쪽 별찍기
    for(int i=0;i<n-1;i++){
    	for(int j=0;j<i+1;j++){
    		cout<<" ";
    	}
    	for(int j=0;j<2*n-2*i-3;j++){
    		cout<<"*";
    	}
    	cout<<endl;
    }
    return 0;
}