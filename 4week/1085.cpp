#include <iostream>
#include <string>
// #include <vector>

using namespace std;

int n;
int x,y,w,h;
int Min1;
int Min2;


int main(){
	freopen("input.txt", "r", stdin);

	cin>>x>>y>>w>>h;
	if(x>abs(x-w)){
		Min1 = abs(x-w);
	}else{
		Min1 = x;
	}

	if(y>abs(y-h)){
		Min2 = abs(y-h);
	}else{
		Min2 = y;
	}

	if(Min1>Min2){
		cout<<Min2;
	}else{
		cout<<Min1;
	}
}
