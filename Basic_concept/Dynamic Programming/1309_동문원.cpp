#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int MOD = 9901;

int N;
int cache[100004][4]; // 0: x, 1: 윗줄, 2: 아랫줄
bool visited[100004][2];

ll func(int x, int state) {
    if(x == N)
        return 1;
    
    int& ret = cache[x][state];
    if(ret != -1)
        return ret;

    //선택 x
    ret = func(x+1, 0) % MOD;  // 
    if(state != 1) { // 이전에 윗줄에 없는 경우
        ret += func(x+1, 1) % MOD;
    }
    if(state != 2){ //이전에 아랫쪽 사자가 없는 경우
        ret += func(x+1, 2) % MOD;
    }

    return ret % MOD;
}



int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    memset(cache,-1,sizeof(cache));
    printf("%lld", func(0, 0) % MOD);
}