#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N,K;
int train[50004];
int cache[50004][5];

int solve(int idx, int choice){
    if(choice == 3)
        return 0;
    if(idx > N)    
        return -INF;
    
    int& ret = cache[idx][choice];
    if(ret != -1)
        return ret;

    ret = solve(idx+1, choice);
    int sum = 0;
    for(int i = 0 ; i < K; i++){
        if(idx+i <= N)
            sum += train[idx+i];
    }
    ret = max(ret, solve(idx + K, choice + 1) + sum);

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &train[i]);
    }
    scanf("%d" , &K);
    memset(cache,-1,sizeof(cache));
    printf("%d", solve(0, 0));
}