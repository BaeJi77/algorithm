#include <iostream>

using namespace std;


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		// cout<<i+1<<endl;
		cout<<i+1<<"\n";
	}
	return 0;
}

//왜 틀린거냐잉
//endl은 버퍼를 버리는 행위인데 이런 행위는 메모리를 잡아먹는다.