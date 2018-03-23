#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

int n;
int number;
string str;
bool check;

int main(){
	freopen("input.txt", "r", stdin);

	stack <char> st;
	cin>>n;
	while(n--){
		cin>>str;
		for(int i=0;i<str.size();i++){
			if(str[i]=='('){
				// cout<<"push call"<<endl;
				st.push(str[i]);
			}else if(str[i]==')'){
				if(st.size()==0){
					check=1;
					// cout<<"pop하지마"<<endl;
					break;
				}else{
					// cout<<"pop call"<<endl;
					st.pop();
				}
			}
		}
		if(check==1||st.size()!=0){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		check=0;
		while(!st.empty()){
			st.pop();
		}
	}
}