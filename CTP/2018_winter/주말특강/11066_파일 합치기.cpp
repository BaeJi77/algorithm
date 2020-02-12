#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N,file[504],psum[504];
int cache[504][504]; //i에서 j까지 파일을 합치는 최솟값

int solve(int i, int j){
    if(i == j)
        return 0;

    int& ret = cache[i][j];
    if(ret != -1)
        return ret;
    
    ret = INF;
    for(int k = i ; k < j ; k++){
        ret = min(ret, solve(i, k) + solve(k+1, j) + psum[j] - psum[i-1]);
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        memset(cache,-1,sizeof(cache));
        for(int i = 1 ; i <= N ; i++){
            scanf("%d" , &file[i]);
            psum[i] = psum[i-1] + file[i];
        }
        printf("%d\n" , solve(1,N));
    }
}