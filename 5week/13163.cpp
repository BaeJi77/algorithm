#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<vector<int> > vt;
int visited[1100];

string str;

void dfs(int here){
	visited[here] = 1;

	int nv=0;
	for(int i=0;i<vt[here].size();i++){
		nv = vt[here][i];

		if(visited[nv] == 1)	continue;
		dfs(nv);
	}

	// for(auto nv : vt[here])
}

int main(){
	freopen("input.txt","r",stdin);
	cin>>n;
	cin>>m;

	vt.resize(n+1);

	int a,b;

	for(int i = 0 ; i < m ; i++){
		scanf("%d %d",&a,&b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	int ans = 0;

	for(int i =1 ; i <= n ;i++){
		if(visited[i] == 0){
			dfs(i);
			ans++;
		}
	}

	printf("%d",ans);



}