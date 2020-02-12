#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

int t;
ll input;
int MAXX;
ll MAXXIDX;

map <ll, int> Map;
map <ll, int>::iterator it;

int main(){
	freopen("input.txt", "r", stdin);
	
	scanf("%d" , &t);
	while(t--){
		scanf("%lld" , &input);
		Map[input]++;
	}

	for(it = Map.begin(); it != Map.end(); it++){
		if(MAXX < it->second){
			MAXX = it->second;
			MAXXIDX = it->first;
		}
	}
	printf("%lld\n" , MAXXIDX);
}