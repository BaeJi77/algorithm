#include <iostream>
#include <stack>
#include <string>


using namespace std;

int n;
string str;
int pushNum;

int main(){
	freopen("input.txt", "r", stdin);
	stack <int> st;

	cin>>n;
	while(n--){
		cin>>str;
		if(str=="push"){
			// cout<<"Push call"<<endl;
			cin>>pushNum;
			st.push(pushNum);
			// cout<<endl;
		}else if(str=="top"){
			// cout<<"Top call"<<endl;
			cout<<st.top()<<endl;
		}else if(str=="size"){
			// cout<<"Size call"<<endl;
			cout<<st.size()<<endl;;
		}else if(str=="empty"){
			// cout<<"Empty call"<<endl;
			cout<<st.empty()<<endl;;
		}else if(str=="pop"){
			// cout<<"Pop call"<<endl;
			if(st.empty()!=1){
				cout<<st.top()<<endl;;
				st.pop();
			}else{
				cout<<"-1"<<endl;
			}
		}
	}

}