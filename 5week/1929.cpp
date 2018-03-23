#include <cstdio>

#define MAXX 1000000

using namespace std;

bool f[MAXX+10];

int n,m;

int main(){
	freopen("input.txt", "r", stdin);


	f[0]=f[1]=true;
	for(int i = 2 ; i*i <= MAXX ; i++){
		if(f[i]==false){
			for(int j = i*i ; j <= MAXX ; j = j + i){
				f[j] = true;
			}
		}
	}

	scanf("%d%d", &n, &m);

	for (int i = n; i <= m; i++) {
		if (!f[i]) 
			printf("%d\n", i);
	}
}


