#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int n,m;
char input[20] ;
map <int , string> mp;
map <int , string>::iterator it;
vector <string> vt;
vector <string>::iterator vit;



int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d" , &n ,&m);
	for(int i = 1 ; i <= n ; i++){
		scanf("%20s" , input);
		mp[i] = input;
		vt.push_back(input);
	}

	for(int i = 0 ; i < m ; i++){
		cin>>input;
		int check = input[0] - '0';
		if(check >= 0 && check <= 9){
			int toInt = stoi(input);
			cout<<mp.find(toInt)->second<<endl;
		}else {
			vit = find(vt.begin() , vt.end() , input);
			int Num = distance(vt.begin(), vit);
			cout<<Num+1<<endl;
			// for(it = mp.begin() ; it != mp.end() ; it++){
			// 	if(it->second == input){
			// 		cout<<it->first<<endl;
			// 	}
			// }
		}
		
	}
}