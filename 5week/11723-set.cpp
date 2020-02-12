#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <set>


using namespace std;

int n;
string str;
int pushNum;


int main(){
	freopen("input.txt", "r", stdin);
	int count=0;
	set <int> set1;
	set <int>::iterator it;
	cin>>n;
	while(n--){
		cin>>str;
		if(str=="add"){
			cin>>pushNum;
			set1.insert(pushNum);
		}else if(str=="check"){
			cin>>pushNum;
			count = set1.count(pushNum);
			cout<<count<<endl;
		}else if(str=="remove"){
			cin>>pushNum;
			set1.erase(pushNum);
		}else if(str=="toggle"){
			cin>>pushNum;
			count = set1.count(pushNum);
			// cout<<set1.find(pushNum);
			if(count){
				set1.erase(pushNum);
			}else{
				set1.insert(pushNum);
			}
		}else if(str=="empty"){
			 set1.clear();
		}
	}
}