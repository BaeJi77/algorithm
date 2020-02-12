#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[1004][1004];
string A,B;

int solve(int x, int y){
    if(x == A.length() || y == B.length()){
        return 0;
    }

    int& ret = cache[x][y];
    if(ret != -1)
        return ret;

    ret = max(solve(x+1, y), solve(x, y+1));
    if(A[x] == B[y])
        ret = max(ret, solve(x+1, y+1) + 1);

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>A>>B;
    memset(cache,-1,sizeof(cache));
    printf("%d\n", solve(0,0));
}
