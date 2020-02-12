#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int cache[44];
vector<int> vt;

int func(int idx){
    if(idx == 2)
        return 2;
    if(idx == 1)
		return 1;
	if(idx == 0)
		return 0;

	int& ret = cache[idx];
	if(ret != -1)
		return ret;
	ret = func(idx-1) + func(idx-2);

	return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d", &M);
	int pre = 0;
    for(int i = 0 ; i < M ; i++){
        int a;
        scanf("%d", &a);
		vt.push_back(a-pre-1);
		pre = a;
    }
	vt.push_back(N-pre);
	memset(cache,-1,sizeof(cache));

	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 2;
	func(41);

	int ans = 1;
	for(int i = 0 ; i < vt.size(); i++){
		ans *= cache[vt[i]];
	}

	printf("%d", ans);
}