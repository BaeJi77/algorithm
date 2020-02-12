#include <iostream>

using namespace std;


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		// cout<<n-1<<endl;
		cout<<n-i<<"\n";
	}
	return 0;
}

//이것은 왜 또 틀린거야...
//endl은 버퍼를 버리는 행위인데 이런 행위는 메모리를 잡아먹는다.