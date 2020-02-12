#include <cstdio>
#include <cmath>

int N, arr[10001];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        int cnt = 0;
        for(int j = 1 ; j <= sqrt(i) ; j++){
            if(i % j == 0)
                cnt++;
        }
        arr[i] = arr[i-1] + cnt;
    }
    printf("%d", arr[N]);
}