#include <cstdio>
#include <string>
#include <iostream>
#include <map>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <vector>
#include <algorithm>

>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
>>>>>>> 1ff6c3c... 18.05.08

using namespace std;

int n,m;
<<<<<<< HEAD
<<<<<<< HEAD
char input[30];
map <string , int> mp;
string arr[100010];
=======
char input[20] ;
map <int , string> mp;
map <int , string>::iterator it;
vector <string> vt;
vector <string>::iterator vit;
>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
char input[30];
map <string , int> mp;
string arr[100010];
>>>>>>> 1ff6c3c... 18.05.08



int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d" , &n ,&m);
	for(int i = 1 ; i <= n ; i++){
<<<<<<< HEAD
<<<<<<< HEAD
		scanf("%s" , input);
		mp[input] = i;
		arr[i] = input;
	}

	for(int i = 0 ; i < m ; i++){
		scanf("%s" , input);
		int check = input[0] - '0';
		if(check >= 0 && check <= 9){
			int toInt = stoi(input);
			cout<<arr[stoi(input)]<<"\n";
		}else {
			printf("%d\n" , mp[input]);
=======
		scanf("%20s" , input);
		mp[i] = input;
		vt.push_back(input);
=======
		scanf("%s" , input);
		mp[input] = i;
		arr[i] = input;
>>>>>>> 1ff6c3c... 18.05.08
	}

	for(int i = 0 ; i < m ; i++){
		scanf("%s" , input);
		int check = input[0] - '0';
		if(check >= 0 && check <= 9){
			int toInt = stoi(input);
			cout<<arr[stoi(input)]<<"\n";
		}else {
<<<<<<< HEAD
			vit = find(vt.begin() , vt.end() , input);
			int Num = distance(vt.begin(), vit);
			cout<<Num+1<<endl;
			// for(it = mp.begin() ; it != mp.end() ; it++){
			// 	if(it->second == input){
			// 		cout<<it->first<<endl;
			// 	}
			// }
>>>>>>> 377e168... 18.04.07 오랜만에 하는 커밋
=======
			printf("%d\n" , mp[input]);
>>>>>>> 1ff6c3c... 18.05.08
		}
		
	}
}