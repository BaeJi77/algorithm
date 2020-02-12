#include <cstdio>
#include <cstring>

using namespace std;

int T, N;
int fi1[44], fi2[44];

int func(int num, int base, int dp[]){
    if(num <= 1){
        return num == base ? 1 : 0;
    }

    int& ret = dp[num];
    if(ret != -1){
        return ret;
    }
    return ret = func(num - 1, base, dp) + func(num - 2, base , dp);
}

int main(){ 
    freopen("input.txt", "r", stdin);
    scanf("%d" , &T);
    memset(fi1, -1, sizeof(fi1));
    memset(fi2, -1, sizeof(fi2));
    while(T--){
        scanf("%d",&N);
        printf("%d %d\n" , func(N, 0, fi1) , func(N, 1, fi2));
    }
}