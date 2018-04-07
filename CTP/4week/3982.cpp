#include <cstdio>
#include <string>
#include <iostream>
#include <map>


using namespace std;

int t;
string fir,sec,temp;
int firNum,secNum;
int MAXX;
string MAXNUM;
map <string , int> mp;
map <string , int>::iterator it;



int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d" , &t);
	while(t--){
		for(int i = 0 ; i < 16 ; i++){
			cin>>fir>>sec;
			cin>>firNum>>secNum;
			if(firNum > secNum){
				mp[fir]++;
			}else{
				mp[sec]++;
			}
		}
		for(it = mp.begin() ; it != mp.end() ; it++){
			if(it->second > MAXX)  {
				MAXX = it->second;
				MAXNUM = it->first;
			}
		}
		cout<<MAXNUM<<endl;
		MAXX = 0;
		MAXNUM = "";
		mp.clear();
	}
	
}