#include <iostream>
#include <stack>
#include <string>
#include <queue>


using namespace std;

int n;
string str;
int pushNum;

int main(){
	freopen("input.txt", "r", stdin);
	queue <int> qu;

	cin>>n;
	while(n--){
		cin>>str;
		if(str=="push"){
			cin>>pushNum;
			qu.push(pushNum);
		}else if(str=="front"){
			if(qu.empty()==1){
				cout<<"-1"<<endl;
			}else{
				cout<<qu.front()<<endl;
			}
		}else if(str=="back"){
			if(qu.empty()==1){
				cout<<"-1"<<endl;
			}else{
				cout<<qu.back()<<endl;
			}
		}else if(str=="size"){
			cout<<qu.size()<<endl;
		
		}else if(str=="empty"){
			cout<<qu.empty()<<endl;
		}else if(str=="pop"){
			if(qu.empty()==1){
				cout<<"-1"<<endl;
			}else{
				cout<<qu.front()<<endl;
				qu.pop();
			}
		}
	}
}